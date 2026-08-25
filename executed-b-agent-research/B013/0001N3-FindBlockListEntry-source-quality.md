** TARGET-REPORT-UID:0001N3 **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B013 B-Report: 0001N3 FindBlockListEntry Source Quality

## Assignment

- UID: `0001N3`
- Target: `source-3/project-documentation/by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B013/research/0001N3-FindBlockListEntry-source-quality.md`
- Scope: B-agent source-quality research report only. I did not edit target docs, support docs, or `by-memory/-coverage-report.md`.
- Prior B013 reports, including `00013E`, `00015H`, `00018U`, and `00019T`, were preserved and not moved or overwritten.

## Executive Recommendation

`0001N3` should stay reconstructable, stay owned/emitted through [UID:0000HS] `BlockListenInputPanes`, and receive first-draft C++ under the current combined-score/emitter gate. The stale "no final C++ under 95/95" wording should be replaced. Current metadata already has `RECONSTRUCTABLE:TRUE`, a valid emitter route to `auto-generated/NexusTK/social/BlockListenInputPanes.cpp`, and average score `87`; after this source-quality pass the target should be raised to `87/90`.

Recommended target metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended source route:

- Direct owner/emitter remains [UID:0000HS] `BlockListenInputPanes`; do not route this shared helper through only `AddToBlockListenInputPane` or `DeleteFromBlockListenInputPane`.
- Keep [UID:0000PM] `FindBlockListEntry_5B74E0` as a name/index support page. Do not emit duplicate C++ from both the by-memory target and the by-global index.
- Place source in `NexusTK/social/BlockListenInputPanes.cpp` as a file-local helper.

Recommended source-facing signature:

```cpp
static SimpleUStringVector::iterator FindBlockListEntry(
    SimpleUStringVector::iterator first,
    SimpleUStringVector::iterator last,
    SimpleUString name);
```

Binary mapping: the first decompiler parameter is the hidden return slot for the iterator object. IDA/Ghidra display it as an explicit output pointer, but the source should read as a normal iterator-returning helper. The fourth source parameter is passed by value; the observed `sub_582B70` call is the by-value wide-string parameter cleanup.

## Evidence Checked

Required process docs:

- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `.codex/AGENTS.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B013/goal.md`
- `source-3/project-documentation/by-structure.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-project-structure/proposed-source-tree.md`

Target and BlockListen support docs:

- `by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md`
- `by-global/FindBlockListEntry_5B74E0.md`
- `by-file/BlockListenInputPanes.md`
- `by-class/AddToBlockListenInputPane.md`
- `by-class/DeleteFromBlockListenInputPane.md`
- `by-memory/0x005b68c0-0x005b7354.BlockListenInputPanes.md`
- `by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md`
- `by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md`
- `by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md`
- `by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md`

String/vector helper docs:

- `by-type/by-struct/SimpleUStringVectorLayout.md`
- `by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md`
- `by-memory/0x00584910-0x0058498b.SimpleUStringVectorPushBack.md`
- `by-type/by-template/StringBaseTemplate.md`
- `by-type/by-struct/SimpleUStringPointerBackedLayout.md`
- `by-memory/0x00582500-0x005829f0.StringBaseConversionAndCrtShims.md`
- `by-memory/0x005829f0-0x00582d80.StringBaseShareAssignAndAccess.md`
- `by-memory/0x005840f0-0x0058415a.WideRangeCompare.md`
- `by-memory/0x00584160-0x005845af.StringBaseAppendAndFind.md`
- `by-memory/0x005845b0-0x005845ec.StringBaseCompareWideLiteral.md`

Neighbor/source-split docs and raw exports:

- `by-file/UserPane.md`
- `by-class/UserPane.md`
- `by-memory/0x005a2530-0x005b8395.UserPane.md`
- `resources/exported_data/functions/0x005b74e0.json`
- `resources/exported_data/functions/0x00582950.json`
- `resources/exported_data/functions/0x005b7560.json`
- `resources/exported_data/functions/0x005b75a0.json`
- `resources/exported_data/functions/0x005b75d0.json`
- `resources/exported_data/functions/0x005b7660.json`
- `resources/exported_data/functions/0x005ad820.json`
- `resources/exported_data/functions/0x005a2530.json`

Coverage/generated evidence:

- `by-memory/-coverage-report.md` current row for [UID:0001N3]
- `auto-generated/-ag-memory-coverage.md` current emits row for [UID:0001N3]
- `project-level/-auto-completion-stats.md` current `84/90` target score row

Prior B-report search:

- Searched B001/B002/B013 executed reports for `0001N3`, `FindBlockListEntry`, `0x005b74e0`, `sub_5B74E0`, `sub_584540`, `sub_582950`, `sub_582B70`, `0x005b7560`, and `0x005b75a0`.
- Relevant prior result: B002 report `00012G-simple-ustring-vector-grow-insert-source-quality.md` names `0x00582b70` as `DestroyWideStringHandle` / `ReleaseWideStringHandle`, matching current string-family docs.

Tool status:

- IDA MCP at `http://127.0.0.1:13337/mcp` was not reachable in this session: `Unable to connect to the remote server`.
- Validator baseline command was run and passed:

> Executable block R001 was removed from this report and preserved verbatim in [0001N3-FindBlockListEntry-source-quality-removed.md](0001N3-FindBlockListEntry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validator output summary: scanned one markdown file; `ok 0001N3 ... UID header exists`; dry run only.

Numeric conversions checked with `tools/int_convert.py` where decimal values are used: `0x73` = 115, `0x4c` = 76, `0x80` = 128, `0x2604` = 9732, `0x2918fc` = 2693372, `0x291900` = 2693376, `0x14` = 20, `0x28` = 40, `0x0d` = 13, `0x02` = 2, `0x03` = 3, and `0x108` = 264.

## Behavior Resolution

Observed binary behavior:

- `sub_5B74E0` is exactly `0x005b74e0-0x005b7553`, size `0x73` / 115 bytes (Verified with `tools/int_convert.py`).
- It has exactly two direct code references in current docs/raw export: `0x005b6d89` in add-block-list submit and `0x005b720d` in delete-block-list confirm.
- It has three callees: `0x00584540`, `0x00582950`, and `0x00582b70`.
- It walks a `SimpleUStringVector` range whose element slots are 4-byte pointer-backed UTF-16 string handles.
- For each slot, it compares the stored wide string against the search key with `0x00582950`.
- On match or end, it writes/returns the resulting iterator.
- It destroys the by-value search string parameter before returning.

Helper identities:

| Raw name | Address | Best source-quality role | Evidence |
| --- | --- | --- | --- |
| `sub_5B74E0` | `0x005b74e0` | `FindBlockListEntry`, file-local `BlockListenInputPanes.cpp` helper | Only two callers are add/delete block-list handlers; loop searches config block-list vector range. |
| `sub_584540` | `0x00584540` | `StringBase::c_str` / `GetStringDataPointer` | Three-byte accessor returning the data pointer; broad fan-in; documented by [UID:0002RS]. |
| `sub_582950` | `0x00582950` | `WideStringCompareNoCase` / `_wcsicmp` wrapper | Raw JSON and [UID:0002RM] show a 9-byte wrapper returning `_wcsicmp(String1, String2)`. |
| `sub_582B70` | `0x00582b70` | `StringBase<wchar_t>` release wrapper / by-value parameter destructor | [UID:0002RN] documents it as wide release/destructor-style wrapper forwarding into wide buffer release. |

Important behavior correction: this helper is a case-insensitive search. The current target says only "wide-string comparison"; support docs should specify that `0x00582950` is the `_wcsicmp` wrapper and equality is `CompareWideNoCase(...) == 0`.

## Field And Type Recommendations

Config field direction:

- The add/delete caller docs already identify the vector range at `dword_67A7C8 + 0x2918fc` through `+0x291900`; these offsets are `2693372` and `2693376` decimal (Verified with `tools/int_convert.py`).
- Because [UID:0001W6] documents a 12-byte `SimpleUStringVector` triplet, the source field should be named as a vector, not as raw begin/end globals.
- Best field name direction: `Config::m_blockListenNames` or `Config::m_blockListNames`.
- Preferred wording in docs: "the block-listen name vector at `g_pConfig + 0x2918fc` (`begin`) and `+0x291900` (`end`), with the capacity field expected at the next dword by `SimpleUStringVectorLayout`."

Iterator/type direction:

- `SimpleUStringVector` element slots are 4-byte pointer-backed wide string handles, not 24-byte inline SSO strings.
- In decompiler terms the iterators look like `const wchar_t **`.
- In source terms this should be written as `SimpleUStringVector::iterator` or an alias such as `BlockListenNameIterator`.
- The search key should be a by-value `SimpleUString` / `StringBase<wchar_t>` object, because the callee performs the destructor/release at the end.

## First-Draft C++

This is ready for the target `RECONSTRUCTION_CPP CODE` block after supervisor acceptance. It intentionally uses source-style iterator/value semantics instead of the decompiler's hidden output pointer.

```cpp
namespace {

static SimpleUStringVector::iterator FindBlockListEntry(
    SimpleUStringVector::iterator first,
    SimpleUStringVector::iterator last,
    SimpleUString name)
{
    const wchar_t *needle = name.c_str();

    for (SimpleUStringVector::iterator it = first; it != last; ++it) {
        if (WideStringCompareNoCase(it->c_str(), needle) == 0) {
            return it;
        }
    }

    return last;
}

} // namespace
```

Alternate lower-level form if `SimpleUStringVector::iterator` is kept as a raw slot pointer during early emission:

```cpp
namespace {

typedef wchar_t *BlockListenName;
typedef BlockListenName *BlockListenNameIterator;

static BlockListenNameIterator FindBlockListEntry(
    BlockListenNameIterator first,
    BlockListenNameIterator last,
    SimpleUString name)
{
    const wchar_t *needle = name.c_str();

    while (first != last) {
        if (WideStringCompareNoCase(*first, needle) == 0) {
            break;
        }
        ++first;
    }

    return first;
}

} // namespace
```

Implementation note: `WideStringCompareNoCase` is the source-quality name for `0x00582950`; if shared string helpers are not declared yet, use the project's eventual wrapper name or `_wcsicmp` through a local helper policy. The target page should not define shared string helper bodies.

## Neighboring Split Review

The neighboring starts mentioned in the target doc are real but not part of `FindBlockListEntry`.

| Range | Current raw function | Best source-quality direction | Owner/source route |
| --- | --- | --- | --- |
| `0x005b7553-0x005b7560` | padding | Thirteen `0xcc` bytes after `FindBlockListEntry` | ignored alignment row if split separately |
| `0x005b7560-0x005b759f` | `sub_5B7560` | constructor for a 0x4c-byte UserPane record containing three SSO-style UTF-16 strings and one byte flag | UserPane-related, likely [UID:0000P1]/[UID:0000FQ], not BlockListen |
| `0x005b75a0-0x005b75ce` | `sub_5B75A0` | constructor for a larger UserPane record: vector-constructs `0x80` / 128 (Verified with `tools/int_convert.py`) records of stride `0x4c` / 76 (Verified with `tools/int_convert.py`) and clears a leading byte | UserPane-related, not BlockListen |
| `0x005b75ce-0x005b75d0` | padding | Two `0xcc` bytes before `ConfirmInputPaneConstructor` | ignored alignment row if split separately |
| `0x005b75d0-0x005b760e` | `sub_5B75D0` | already documented `ConfirmInputPane` constructor | InputPanes / ConfirmInputPane |

Raw evidence:

- `resources/exported_data/functions/0x005b7560.json`: constructor initializes three SSO-style wide strings at offsets `0x00`, `0x18`, and `0x30` with length `0`, capacity `7`, and NUL terminators, then clears byte `+0x48`.
- `resources/exported_data/functions/0x005b75a0.json`: calls `eh vector constructor iterator` on `this + 4`, stride `0x4c`, count `0x80`, ctor `sub_5B7560`, dtor `sub_5B7660`, then clears `*this`.
- `resources/exported_data/functions/0x005b7660.json`: destructor releases the same three SSO wide-string fields, using `sub_5C7526` and `__invalid_parameter_noinfo_noreturn` for large-allocation validation.
- `resources/exported_data/functions/0x005a2530.json`: `UserPane` constructor vector-constructs 128 larger records at stride `0x2604` / 9732 (Verified with `tools/int_convert.py`) using `sub_5B75A0`.
- `resources/exported_data/functions/0x005ad820.json`: a no-direct-caller retained helper uses `sub_5B7560`/`sub_5B7660` for a stack temporary array while swapping two of the 0x2604 UserPane records.

Recommended future split names:

- `0x005b7560-0x005b759f.UserPaneCollectionNameRecordConstructor.md`
- `0x005b75a0-0x005b75ce.UserPaneCollectionRecordConstructor.md`

Confidence for exact semantic names is medium. The constructor/destructor shape and UserPane route are strong; exact record meaning needs a focused UserPane record-layout pass before final names are frozen.

## Open Questions And Resolution Attempts

- `FindBlockListEntry` versus `FindBlockListenEntry`: no PDB/source symbol was found. Existing target, user assignment, and support docs use `FindBlockListEntry`. Keep the current name, but describe the feature as block-listen names in prose.
- `SimpleUString` versus `mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t>>`: compiler metadata favors `mystr::StringBase`, while older recovery labels and vector docs use `SimpleUString`. This should be settled in shared string docs. It is not a blocker for target C++ if `SimpleUString` remains the local facade alias.
- Exact config field name for `g_pConfig + 0x2918fc`: no source symbol recovered. Best-supported names are `m_blockListenNames` or `m_blockListNames`. Use one consistently in `Config`/BlockListen docs after the config layout pass accepts it.
- Whether to split the target: no split needed. The target is one exact function with padding on both sides. The unrelated `0x005b7560` and `0x005b75a0` helpers should be their own future pages, not children or extensions of this helper.
- Live IDA MCP could not be reached in this session. Existing docs record live IDA evidence from 2026-06-05/2026-06-14, and raw exported JSON agrees with those claims. Keep confidence at `90`, not above final-audit range.

## Recommended Target Doc Changes

1. Replace the Status final-C++ sentence with:

```text
Reconstructable as a private BlockListenInputPanes helper. Under the current combined-score/emitter gate, this page is eligible for first-draft C++ after source-quality resolution: the helper is `RECONSTRUCTABLE:TRUE`, emits through [UID:0000HS], and should be scored `87/90` after resolving the string helper roles below.
```

2. Replace the Behavior section with:

```text
`FindBlockListEntry` searches a `SimpleUStringVector` iterator range for a block-listen name. The vector stores 4-byte pointer-backed UTF-16 string handles. The source-level search key is passed by value as a `SimpleUString` / `StringBase<wchar_t>` object; the decompiler exposes this as stack/vararg state because MSVC destroys the by-value parameter inside the callee.

For each iterator, the helper obtains the search key data through `0x00584540` (`StringBase::c_str` / `GetStringDataPointer`), compares the current slot with the key through `0x00582950` (`WideStringCompareNoCase`, a `_wcsicmp` wrapper), stops when the comparison returns `0`, and returns the matching iterator or `end`. The observed `0x00582b70` call is the wide-string by-value parameter release/destructor path.
```

3. Add a Source-Quality Names table using the helper table from this report.

4. Add the first-draft C++ block from this report.

5. Update Reconstruction Notes:

```text
Keep this helper file-local in [UID:0000HS] `BlockListenInputPanes`. Both direct callers are block-list add/delete handlers, while the shared string and vector helpers remain dependencies owned by StringBase/StringUtil. Do not duplicate emitted source in [UID:0000PM] `FindBlockListEntry_5B74E0`.
```

6. Replace the neighboring helper note with:

```text
The functions at `0x005b7560-0x005b759f` and `0x005b75a0-0x005b75ce` are real but unrelated UserPane record constructor helpers. They sit after `0x005b7553-0x005b7560` padding and before `0x005b75ce-0x005b75d0` padding / [UID:0001N4] `ConfirmInputPaneConstructor`. They should be split under UserPane/source-record layout research, not merged with this BlockListen helper.
```

## Recommended Support Doc Changes

- [UID:0000HS] `BlockListenInputPanes`: update the `FindBlockListEntry` row/evidence to replace raw `sub_584540/sub_582950/sub_582B70` wording with `StringBase::c_str`, `WideStringCompareNoCase` / `_wcsicmp` wrapper, and wide release wrapper. Mention current 85/85 gate rather than stale 95/95 no-code wording.
- [UID:0000PM] `FindBlockListEntry_5B74E0`: keep as index/support. Update "Final C++ remains blank" to say the by-memory target owns emitted source to avoid duplicate code. Add the case-insensitive compare detail.
- [UID:00000A] `AddToBlockListenInputPane`: state that duplicate detection is case-insensitive through `FindBlockListEntry` / `_wcsicmp` wrapper.
- [UID:00003N] `DeleteFromBlockListenInputPane`: state that delete lookup is case-insensitive through `FindBlockListEntry` / `_wcsicmp` wrapper.
- [UID:0001N0] and [UID:0001N2] exact caller pages: replace raw `sub_5B74E0` where present with source-quality helper name and add the `Config::m_blockListenNames` field-name direction.
- [UID:0001MW] aggregate: keep `FindBlockListEntry` separate and add that `0x005b7560/0x005b75a0` are UserPane record constructor split candidates outside the BlockListen aggregate.
- UserPane support docs: future split pass should add the two helper rows named above and connect them to the 0x2604 UserPane record array and the retained swap helper at `0x005ad820`.

## Score Recommendation

Recommended target score: `87/90`.

Justification:

- Completion increases from `84` to `87` because helper names/signatures are now resolved enough for source-quality: hidden iterator return, by-value string parameter, 4-byte `SimpleUStringVector` slots, case-insensitive compare wrapper, `c_str` accessor, release wrapper, file-local owner, and unrelated neighboring helper split are all documented.
- Confidence remains `90`, not higher, because no source/PDB symbol proves the exact original helper name or `SimpleUString` versus `StringBase` facade spelling, and IDA MCP was unavailable for a fresh live session.
- The target remains far below the rare `95+` threshold because shared string API names, final config field names, and future UserPane record splits still need final-source review.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` in this task. If the supervisor accepts the target update, replace the existing [UID:0001N3] row with:

```text
    - [UID:0001N3][0x005b74e0-0x005b7553.FindBlockListEntry](by-memory/0x005b74e0-0x005b7553.FindBlockListEntry.md) 0x005b74e0-0x005b7553 | private helper | FindBlockListEntry : reconstructable : 87% : strong : B013 source-quality pass resolves the stale 95/95 no-code rationale under the current combined-score/emitter gate, confirms this as a file-local BlockListenInputPanes helper with only add/delete block-list callers at 0x005b6d89 and 0x005b720d, maps the hidden iterator return and by-value pointer-backed wide-string key, resolves `0x00584540` as `StringBase::c_str`, `0x00582950` as the `_wcsicmp`/case-insensitive wide compare wrapper, and `0x00582b70` as wide-string release/destructor support, preserves adjacent padding and unrelated UserPane neighbor split needs, and supplies first-draft source-style C++.
```

If the supervisor creates future split pages for the neighboring UserPane helpers, use these row bodies after real UIDs are assigned:

```text
    - [UID:NEW][0x005b7560-0x005b759f.UserPaneCollectionNameRecordConstructor](by-memory/0x005b7560-0x005b759f.UserPaneCollectionNameRecordConstructor.md) 0x005b7560-0x005b759f | constructor helper | UserPaneCollectionNameRecordConstructor : reconstructable : 78% : medium-strong : Raw function initializes a 0x4c-byte UserPane record with three SSO-style UTF-16 fields and one byte flag; referenced by the 0x005b75a0 array constructor and the retained 0x005ad820 record-swap helper; exact semantic field names require a UserPane record-layout pass.
    - [UID:NEW][0x005b75a0-0x005b75ce.UserPaneCollectionRecordConstructor](by-memory/0x005b75a0-0x005b75ce.UserPaneCollectionRecordConstructor.md) 0x005b75a0-0x005b75ce | constructor helper | UserPaneCollectionRecordConstructor : reconstructable : 78% : medium-strong : Raw function vector-constructs 0x80 / 128 nested 0x4c-byte UserPane collection/name records (Verified with `tools/int_convert.py`) through 0x005b7560 and clears a leading byte; called as the 0x2604-stride UserPane record constructor from UserPane construction; exact semantic field names require a UserPane record-layout pass.
```

The `UID:NEW` placeholders are not paste-ready until validator-created UIDs exist. The [UID:0001N3] replacement row above is paste-ready.

## Validation Commands Needed After Implementation

Run after editing the target/support docs:

> Executable block R002 was removed from this report and preserved verbatim in [0001N3-FindBlockListEntry-source-quality-removed.md](0001N3-FindBlockListEntry-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the neighbor split pages are created in the same implementation pass, validate each new by-memory page with `--apply`, then run a targeted autogen dry-run.

## IDA Rename/Type/Comment Recommendations

| Address | Recommendation | Confidence |
| --- | --- | --- |
| `0x005b74e0` | Rename `sub_5B74E0` to `FindBlockListEntry`; comment "file-local BlockListenInputPanes helper; case-insensitive search over block-listen name vector." | high |
| `0x005b74e0` | Use source signature `SimpleUStringVector::iterator FindBlockListEntry(SimpleUStringVector::iterator first, SimpleUStringVector::iterator last, SimpleUString name)`; in IDA, keep hidden return-slot awareness if applying a low-level prototype. | medium-high |
| `0x00584540` | Rename/document as `StringBase_GetDataPointer` or `StringBase_c_str`; type as returning `const wchar_t *` for wide-string consumers. | high for role, medium for exact API spelling |
| `0x00582950` | Rename/document as `WideStringCompareNoCase`; type `int __cdecl WideStringCompareNoCase(const wchar_t *lhs, const wchar_t *rhs)`. | high |
| `0x00582b70` | Rename/document as `ReleaseWideStringHandle` / `StringBaseWide_Release`; type as destructor/release wrapper over a pointer-backed UTF-16 handle. | high for role, medium for exact API spelling |
| `0x005b7560` | Future rename candidate `UserPaneCollectionNameRecord_Constructor`. | medium |
| `0x005b75a0` | Future rename candidate `UserPaneCollectionRecord_Constructor`. | medium |
| `0x005b7660` | Future rename candidate `UserPaneCollectionNameRecord_Destructor`. | medium |

Do not apply IDA-side edits from this B-agent report unless the supervisor explicitly requests an implementation/IDA callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0001N3-FindBlockListEntry-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001N3"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001N3-FindBlockListEntry-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0001N3-FindBlockListEntry-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001N3"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
