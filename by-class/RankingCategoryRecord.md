*** UID:0000BL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <time.h>
#include <vector>

struct RankingUserEntry
{
    int categoryId;
    int rank;
    wchar_t name[32];
    int score;
};

class RankingCategoryRecord
{
    friend class RankingCategoryCollection;

public:
    RankingCategoryRecord()
        : m_totalRankCount(0),
          m_loadedRowsCategoryId(-1),
          m_localPlayerRank(-1),
          m_localPlayerScore(-1)
    {
    }

    short GetListIndex() const;
    int GetCategoryId() const;
    int GetStateCode() const;
    void SetListIndex(short listIndex);
    void SetCategoryId(int categoryId);
    void SetStateCode(int stateCode);
    tm GetStartTime() const;
    tm GetEndTime() const;
    const wchar_t* GetTitleText() const;
    void SetTitleText(const wchar_t *title);
    RankingUserEntry* GetUserEntryAt(int index);
    void SetStartTimeFromPackedDateTime(int packedDate, int packedTime);
    void SetEndTimeFromPackedDateTime(int packedDate, int packedTime);
    void SetTotalRankCount(int totalRankCount);
    void AppendUserEntry(const RankingUserEntry& entry);
    void ResetUserEntries();

private:
    short m_listIndex;
    int m_categoryId;
    int m_stateCode;
    tm m_startTime;
    tm m_endTime;
    wchar_t m_title[256];
    int m_totalRankCount;
    std::vector<RankingUserEntry> m_userEntries;
    int m_loadedRowsCategoryId;
    int m_localPlayerRank;
    unsigned char m_reservedLocalPlayerFooter[0x40];
    int m_localPlayerScore;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingCategoryRecord

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Confidence: very strong for method boundaries, exact 0x2b0 layout, standard 32-bit `tm` identity, by-value accessor ABI, packed-setter behavior, caller sets, naturally aligned source declaration, and record-owned vector abstraction; strong for the highest-probability original method/field spellings.
- C++ reconstruction: the complete source-facing declaration, including the exact inline partial default constructor and narrow `RankingCategoryCollection` friendship required by UID0003WS and UID0003WT, is in formal H. Formal CPP contains only `[[CHILDREN]]`, so exact by-memory method definitions attach in source without duplicating declarations. Emitter position `0` deliberately places this complete element type before [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md), whose formal header instantiates `std::vector<RankingCategoryRecord>` at position `10`.
- Score: `94/95`, unchanged. Default construction, layout, member lifetime, parser access, and the legal private-write route are source-ready; stripped retail field/method spellings remain the bounded confidence cap.

## Class Purpose

`RankingCategoryRecord` stores one ranking event/category definition plus its loaded user rows. The record includes list index, category id, state code, standard `tm` start/end values, title text, and a `std::vector<RankingUserEntry>`.

## Exact Partial Default Construction

[UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md) and the independent initial-page parser at `0x0045c560` inline the same source constructor contract:

- `m_userEntries` is default-constructed as an empty standard vector.
- `m_totalRankCount` is `0`.
- `m_loadedRowsCategoryId`, `m_localPlayerRank`, and `m_localPlayerScore` are `-1`.
- `m_listIndex`, `m_categoryId`, `m_stateCode`, both `tm` objects' unassigned fields, the title tail, and `m_reservedLocalPlayerFooter` are not initialized by the constructor. Parsers assign the live category fields before append; fixed-byte implicit copy preserves every remaining span.

The exact compiler-folded constant at `0x00610bb0` is `00 00 00 00 00 00 00 00 00 00 00 00 ff ff ff ff`, SHA256 `34885EA2EF8490886FAE553C8CE7FFB5A27563825E5F6CE02784875D1ACE0E47`. It covers the three null vector pointers followed by `m_loadedRowsCategoryId = -1`. Its only inbound data xrefs are `0x0045c43a` in UID0003WR and `0x0045c710` in the initial-page parser; adjacent scalar stores supply the other three initial values.

This is an inline default constructor, not an out-of-line child body. It does not suppress or replace the implicit copy constructor: [UID:0003X4][0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep](by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md) remains compiler-generated memberwise copy with one nested-vector deep copy. Whole-record zeroing and an explicit copy-constructor declaration/body are rejected.

## Initial-Page Private Metadata Access

[UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) constructs records through the public setters, but its matched-record page commit has no setter/helper calls for every proved metadata field. The source-ready child therefore requires the exact narrow formal-H declaration `friend class RankingCategoryCollection;`; the record fields remain private and no broader public mutator API is invented.

The optional-local branch reads a signed flag and executes only for values `1..127`. Its material stores are exactly loaded rows category id at `+0x264`, local player score at `+0x2ac`, local player rank at `+0x268`, and state through `SetStateCode` at `+0x08`. The source assignment order is loaded category id, score, rank, then state. Before that branch, the matched-record reset clears only the logical row-vector end and restores local rank to `-1` while preserving vector capacity.

No target instruction stores packet data to `+0x26c..+0x2ab`. Complete target-store review and the sibling-parser comparison exclude a local-player-name or opaque footer payload from UID0003WS; the footer name painted by `RankingUserListPane` comes from global `word_69BEE0`. The 64-byte record span remains reserved/copied storage because implicit memberwise copy preserves it, but it is not initialized by the partial constructor and is not authored as a parser destination. An absent optional-local block consequently leaves the constructor/reset baseline: loaded category id `-1`, local rank `-1`, local score `-1`, category-list state retained, and reserved tail untouched.

This friendship does not alter physical size, natural alignment, implicit copy/destruction, or the `0x2b0` stride. It grants only class-level C++ access needed to express already-proved stores; UID0003WS still uses the public row append, total setter, category setters, and row reset abstractions where those methods exist.

## Ranking-Row Private Metadata And Tail Exclusion

[UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) independently requires the same narrow `friend class RankingCategoryCollection;` declaration and does not justify public metadata setters. It operates on an already-selected record rather than rebuilding category definitions:

- Selection-id mismatch or failure to find the `0x2b0` record returns before mutation.
- A found record first clears `m_userEntries` without freeing capacity through `ResetUserEntries()`, then explicitly sets `m_localPlayerRank = -1`.
- A signed-positive optional flag writes local rank at `+0x268`, local score at `+0x2ac`, loaded category id at `+0x264`, and state at `+0x08` in the observed rank/cursor/score/id/state order. It writes no byte at `+0x26c..+0x2ab`.
- If optional metadata is absent, loaded id, state, reserved tail, and local score retain their preceding values while rank remains `-1`. This differs from UID0003WS's freshly constructed `-1` baseline and is preserved deliberately.
- Each exact `0x4c` row is category id, rank, 32-WCHAR name, and score. The source sets score to `-1` before the secure name copy and assigns the packet score immediately before `AppendUserEntry`.
- Final total at `+0x254` is assigned only after all rows append. A later conversion, secure-copy, allocation, or range-check failure does not roll back the reset or prior appends.

The formal friend declaration was already present from the accepted UID0003WS callback at the required location immediately after the class opening brace and before `public:`. UID0003WT reuses that exact legal access route; no declaration duplication, layout change, seventeenth record method, or reserved-tail field reinterpretation is introduced.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GetListIndex` | `0x0045bf60-0x0045bf63` | Returns the record list index. |
| `GetCategoryId` | `0x0045bf70-0x0045bf73` | Returns the category id at record offset `+4`. |
| `GetStateCode` | [UID:0002K2][0x0045bf80-0x0045bf84.RankingCategoryRecordGetStateCode](by-memory/0x0045bf80-0x0045bf84.RankingCategoryRecordGetStateCode.md) | Exact four-byte const `int` accessor for `m_stateCode` at `+0x08`; state `0` enables the action/selects the first glyph, state `1` is the post-claim/second-glyph state, and state `2` disables the action and suppresses the glyph. |
| `GetStartTime` | [UID:0002K3][0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts](by-memory/0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md) | Returns `m_startTime` at `+0x0c` by value. MSVC x86 lowers the 36-byte `tm` return through a hidden result pointer; the authored source has no explicit output parameter. |
| `GetEndTime` | [UID:0002K4][0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts](by-memory/0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md) | Returns `m_endTime` at `+0x30` by value through the symmetric hidden-result lowering. |
| `GetTitleText` | `0x0045bfd0-0x0045bfd3` | Returns wide title pointer at record offset `+84`. |
| `GetUserEntryAt` | [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md) | Exact non-const mutable row accessor over `m_userEntries`: computes a signed count, returns null when `count <= index`, and otherwise returns `&m_userEntries[index]`. It deliberately has no lower-bound guard; the sole paint caller supplies only `0..9`. |
| `SetListIndex` | UID000428 [0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex](by-memory/0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex.md) | Raw source-shaped setter that sign-extends a `short` and stores record offset `+0x00`; current MCP keeps no-function/zero-xref evidence as a confidence cap; first-draft C++ populated. |
| `SetCategoryId` | UID000429 [0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId](by-memory/0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId.md) | Raw source-shaped setter for record offset `+0x04`; current MCP confirms no IDA function object, zero direct xrefs, independent `ret 4`, and padding to the state setter; first-draft C++ populated. |
| `SetStateCode` | [UID:0004YY][0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode](by-memory/0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode.md) | Raw source-shaped setter for record offset `+0x08`; current MCP confirms no IDA function object, zero direct xrefs, independent `ret 4`, and padding to the packed start-time setter; first-draft C++ populated. |
| `SetStartTimeFromPackedDateTime` | [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md) | Writes direct packed components to `m_startTime.tm_year/tm_mon/tm_mday/tm_hour/tm_min/tm_sec`; leaves `tm_wday/tm_yday/tm_isdst` untouched. |
| `SetEndTimeFromPackedDateTime` | [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) | Writes the same six direct components into `m_endTime`; leaves the final three `tm` fields untouched. |
| `SetTitleText` | UID00042B [0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText](by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md) | Raw source-shaped `wcscpy_s(m_title, 0x100, title)` setter for the wide title buffer after the K8 postpad; current MCP confirms no IDA function object and zero direct xrefs; first-draft C++ populated. |
| `SetTotalRankCount` | UID00042C [0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount](by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md) | Raw source-shaped setter for `m_totalRankCount` at offset `+0x254`, immediately before `AppendUserEntry`; current MCP confirms no IDA function object and zero direct xrefs; first-draft C++ populated. |
| `AppendUserEntry` | `0x0045c1e0-0x0045c238` | Appends one `RankingUserEntry` row to the `+0x258/+0x25c/+0x260` vector; source-facing signature should be `void AppendUserEntry(const RankingUserEntry& entry)`. The fast path copies `categoryId`, `rank`, inline `name[32]`, and `score`, while the full path grows through [UID:0003X1][0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth](by-memory/0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth.md). The binary return is a copied trailing-dword/growth-helper artifact ignored by the row parser, not a proved source return. |
| `ResetUserEntries` | [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md) | Exact `void` method over `[0x0045c240,0x0045c257)`: source-level `m_userEntries.clear()` lowers to physical end=begin without releasing capacity, then `m_localPlayerRank = -1`. The sole page-request caller ignores residual `EAX`. |

## ResetUserEntries Source Closure

[UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md) now closes the record's clear/reset source shape without exposing compiler container internals:

- The exact 23-byte body copies the physical vector begin at `+0x258` into end at `+0x25c`, preserves capacity end at `+0x260`, and stores `-1` to `m_localPlayerRank` at `+0x268`.
- The class-level source operation is `m_userEntries.clear()`. `RankingUserEntry` is trivial, so no destructor loop is required; the separate vector destroy helper at `0x0045d5f0` frees and zeros the triplet.
- Category-list construction and both ranking-page parsers establish the same empty-vector/rank-`-1` state before appending rows. `RankingUserListPane::OnPaint` consumes a positive local rank for the footer.
- The only code xref is `0x004594f7` in `RankingDialog__RequestRankingPage`, whose next instruction overwrites `EAX`. This confirms the existing formal-H `void ResetUserEntries();` declaration.
- Exact method bytes are `8B 81 58 02 00 00 89 81 5C 02 00 00 C7 81 68 02 00 00 FF FF FF FF C3`, body SHA256 `1B79E28803B9FEDD079B4D54D1FA4F991F40AD7D4039CC438CC5B6F41CD0A37D`.
- The method definition remains a child emitted into `NexusTK/ui/dialogs/RankingDialog.cpp`. This class owns the declaration and `std::vector<RankingUserEntry>` member in `RankingDialog.h`; no duplicate H belongs on the by-memory child.

## Layout Notes

- IDA collection parsers and deep-copy helpers prove a record stride of `0x2b0` / `688` bytes.
- `m_listIndex` occupies `+0x00..+0x01`. The compiler supplies natural alignment at `+0x02..+0x03` before `m_categoryId` at `+0x04`; there is no evidence for a source-authored `m_padding02` member.
- `m_stateCode` is a four-byte `int` at `+0x08`. Category parsers write a packet byte into the 32-bit slot, the raw setter accepts a four-byte argument, and live callers consistently distinguish states `0`, `1`, and `2`.
- [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md) provides an exact source-level accessor/setter pair over these fields. It compares the BE32 response category id with `m_categoryId` at `+0x04` and, only for nonzero status, stores claimed state `1` to `m_stateCode` at `+0x08` on the first matching record.
- The target binary inlines both trivial methods. Reconstructed source uses `GetCategoryId()` and `SetStateCode(1)`; the direct compare/store does not imply duplicate fields, collection-owned accessors, or a second record type.
- User-entry stride is `0x4c` / `76` bytes.
- Start/end packed date-time setters split `YYYYMMDD`-like and `HHMMSS`-like integers into six `int` fields inside each 36-byte `tm` value.
- The existing 32-bit `tm` layout is an exact nine-int structural match: `tm_sec`, `tm_min`, `tm_hour`, `tm_mday`, `tm_mon`, `tm_year`, `tm_wday`, `tm_yday`, and `tm_isdst`. The members begin at record offsets `+0x0c` and `+0x30`.
- This client stores protocol month and full-year values directly in `tm_mon`/`tm_year` and prints them directly. Source must not apply conventional C-library normalization, and it must not initialize `tm_wday/tm_yday/tm_isdst` because checked construction paths leave them untouched.
- Wide title text begins at `+0x54` and is best modeled as `wchar_t title[256]`, a `0x200`-byte buffer ending at `+0x254`.
- `+0x254` is `totalRankCount` or `totalUserCount`; subcommand `2` and `3` parsers store the final total there and `RankingUserListPane::OnPaint` formats it with `"Total : %d"`.
- `+0x258/+0x25c/+0x260` are the physical begin/current-end/capacity slots of one 32-bit `std::vector<RankingUserEntry>`. The three pointers remain essential compiler-layout evidence, but the developer-facing declaration is one `std::vector<RankingUserEntry> m_userEntries` member.
- [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md) proves the source accessor is non-const and returns a mutable row pointer. Its signed upper-bound-only condition preserves the executable's negative-index before-begin pointer behavior; an added `index >= 0` check, `at()`, unsigned-only comparison, or `const_cast` is rejected because none appears in the binary.
- [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md) is the source-authored record method over that triplet. [UID:0003X1][0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth](by-memory/0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth.md)-[UID:0003X3][0x0045d370-0x0045d419.RankingUserEntryVectorClone](by-memory/0x0045d370-0x0045d419.RankingUserEntryVectorClone.md) are generated/container support for growth, copy, and clone mechanics, not separate gameplay methods to expose in this class API.
- `+0x264` is `loadedRowsCategoryId` / `currentRowsCategoryId`, written from the category id when row metadata is loaded.
- `+0x268` is `m_localPlayerRank`, reset to the unavailable sentinel `-1` by `ResetUserEntries` and displayed by `RankingUserListPane::OnPaint` only when positive.
- `+0x26c-+0x2ab` is best modeled as copied/reserved local-player footer tail storage. Its 64-byte size matches a possible wide-name buffer, and record deep-copy preserves it, but the checked subcommand `2`/`3` parsers do not write it and `RankingUserListPane::OnPaint` obtains the displayed footer name from global `word_69BEE0` via `0x005a2dc0`.
- `+0x2ac` is `localPlayerScore` / `localPlayerValue`, displayed in the local-player footer.
- See [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md) for the current offset table.

## UID0003X4 Implicit Copy Construction

[UID:0003X4][0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep](by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md) is the reviewed compiler lowering of this class's implicit copy constructor, not a developer-authored member requiring a declaration or definition:

- The exact body is `[0x0045d420,0x0045d4f8)`, 216 bytes, 57 instructions, one basic block, body SHA256 `02E0572F07330D31B77690BD8BD7902EA80D564CB2A5B9305A0B1B57C51527E3`.
- It copies fixed storage `+0x000..+0x257`, deep-copy constructs only `m_userEntries` at physical `+0x258/+0x25c/+0x260` through [UID:0003X3][0x0045d370-0x0045d419.RankingUserEntryVectorClone](by-memory/0x0045d370-0x0045d419.RankingUserEntryVectorClone.md), then copies `+0x264..+0x2af` and returns the destination.
- The fixed spans cover list index plus natural alignment, category/state, both 36-byte `tm` members, the 512-byte title, total-rank count, loaded-rows category, local-player rank, the 64-byte reserved/footer tail, and local-player score. Natural padding at `+0x02..+0x03` and the vector triplet remain physical compiler-layout evidence, not source members.
- Five direct uses exhaust reachability: parser fast appends at `0x45c4f1` and `0x45c7cb`, outer-vector growth copies at `0x45d07b` and `0x45d0a9`, and range copy at `0x45d6a8`. Parser end pointers advance only after successful construction, while compiler cleanup destroys nested vectors on temporary, old, and partial ranges.
- The target has zero data xrefs and no VA/RVA/raw-offset pointer route, vtable slot, callback, string, protocol, resource, custom branch, or second callee. Those negatives reject a source-authored helper, parser method, collection API, shallow whole-record copy, or standalone utility.
- Source remains this existing class declaration. Do not add an explicit copy-constructor declaration, raw begin/end/capacity fields, authored alignment member, or `RankingCategoryRecordCopyConstructDeep` body. The selected period compiler/library must regenerate equivalent memberwise copy, nested-vector allocation/copy, throw behavior, and caller cleanup.
- UID0003X4 is therefore `94/95`, `RECONSTRUCTABLE:FALSE`, non-emitting, semantically owned by this class, and blank in formal CPP/H. `RankingCategoryRecordCopyConstructDeep` is recovery terminology rather than proved original source spelling.

[UID:0003YU][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md) uses UID0003X4 at `0x45d6a8` while copying a half-open outer-vector range in exact `0x2b0` record steps. This relation confirms that each destination record receives the same implicit memberwise copy and nested-vector deep copy described above. It does not make UID0003YU a `RankingCategoryRecord` method or justify an explicit range-copy API: UID0003YU is collection-vector support semantically owned by UID0000BK, while this class owns only the element semantics regenerated from its existing declaration. UID0003YU remains `94/95`, false/non-emitting, and blank in formal CPP/H; this class remains `93/95` with its current formal source unchanged.

On exception, UID0003YU destroys only the successfully constructed record prefix through UID0003X5/UID0003YS and the record-owned `m_userEntries` teardown at `+0x258`. That external rollback is the compiler consequence of the implicit record copy and the nontrivial standard-vector member. Recovered source must retain the ordinary C++03 class member and standard outer-vector operation rather than add a range constructor, shallow `memcpy`, explicit EH cleanup, raw vector triplet, or binary-helper declaration to `RankingCategoryRecord`.

## Resolved Raw Setter Children

The accepted B001 2026-06-23 current-session pass resolves the former adjacent raw setter gap. These helpers are source-shaped record methods even though IDA does not model function objects at their starts and `xrefs_to` reports zero inbound refs. They are not padding, not K7/K8 tail bytes, and not collection-owned parser bodies.

| Child | Range | Raw proof | Source-facing disposition |
| --- | --- | --- | --- |
| UID000428 [0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex](by-memory/0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex.md) | `0x0045c020-0x0045c02d` | `movsx [ebp+8]` into record `+0x00`, `ret 4`, padding to `0x0045c030`; no IDA function object and zero direct xrefs. | `void SetListIndex(short listIndex);` with first-draft C++. |
| UID000429 [0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId](by-memory/0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId.md) | `0x0045c030-0x0045c03d` | Stores argument into record `+0x04`, `ret 4`, padding to `0x0045c040`; no IDA function object and zero direct xrefs. | `void SetCategoryId(int categoryId);` with first-draft C++. |
| [UID:0004YY][0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode](by-memory/0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode.md) | `0x0045c040-0x0045c04d` | Stores argument into record `+0x08`, `ret 4`, padding to [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md); no IDA function object and zero direct xrefs. | `void SetStateCode(int stateCode);` with first-draft C++. |
| UID00042B [0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText](by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md) | `0x0045c1b0-0x0045c1cb` | `wcscpy_s(this + 0x54, 0x100, title)`, after K8 postpad and before total-count setter; no IDA function object and zero direct xrefs. | `void SetTitleText(const wchar_t *title);` with first-draft C++. |
| UID00042C [0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount](by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md) | `0x0045c1d0-0x0045c1e0` | Stores argument into record `+0x254`, immediately followed by [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md); no IDA function object and zero direct xrefs. | `void SetTotalRankCount(int totalRankCount);` with first-draft C++. |

Accepted rejected alternatives: do not merge these helpers into [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md), [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md), or [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md); do not hide them as padding; do not assign them to [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) merely because parsers populate records. The direct semantic owner is this record class.

## Storage Helper Split

The former broad [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) page is now a non-emitting split/index. Its user-entry vector helper children [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md) and [UID:0003YV][0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage](by-memory/0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage.md) attach here as generated/container support for the record-owned `RankingUserEntry` vector. Formal C++ stays blank on those helper pages because this class declaration should regenerate equivalent container support.

### UID0003YT Vector Teardown Lowering

The authored source cause for [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md) is this class's existing `std::vector<RankingUserEntry> m_userEntries` member and ordinary record lifetime, not a developer-authored helper. The exact 99-byte specialization operates on the physical begin/end/capacity triplet at `+0x258/+0x25c/+0x260`. A null begin returns; otherwise it derives the capacity allocation span using the `0x4c` row stride, handles small allocations directly, recovers the raw allocation from `begin[-1]` for spans at least `0x1000`, and enforces `(begin - raw - 4) <= 0x1f`. The no-return failure route is exact runtime symbol `__invalid_parameter_noinfo_noreturn`. The successful route calls `sub_5C7526` and clears begin, end, and capacity in order.

No element-destructor loop is present because `RankingUserEntry` is trivially destructible. This storage release is distinct from [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md), whose source-level `m_userEntries.clear()` resets end and local-player rank without freeing capacity. The teardown is reached by nine lifetime/EH routes at `0x45bf56`, `0x45c2e8`, `0x45c514`, `0x45c5b6`, `0x45c7ee`, `0x45d0f9`, `0x45d516`, `0x45d548`, and `0x45d5d6`.

The `0x45bf56` route is inside the existing `[0x0045bf50,0x0045bf5b)` tail chunk owned by `sub_45C2A0`: `loc_45BF50` adjusts `ecx` by `+0x258`, then the second instruction tail-jumps to the teardown. The adjacent five bytes `[0x0045bf5b,0x0045bf60)` are a separate `0xcc` data item. The earlier ownerless-tail theory and the single-underscore runtime spelling are retained only as rejected historical interpretations.

UID0003YT is therefore `RECONSTRUCTABLE:FALSE`, with blank emitter and formal CPP/H. This class remains `93/95`, and its existing formal H declaration is unchanged. Runtime equivalence still requires the selected compiler/container implementation to reproduce the observed `0x4c`-stride capacity release, large-allocation validation, free, and triplet clear without introducing decompiler labels or raw triplet fields into human source.

### UID0003YS Outer-Range Rollback Support

[UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md) supplies external lifetime support when the owning collection's `std::vector<RankingCategoryRecord>` growth fails after partially constructing destination records. Its 43-byte half-open loop advances by exact record size `0x2b0` and passes `record + 0x258` to UID0003YT, so each successfully constructed record's `m_userEntries` allocation is released before the outer failed allocation is freed and the exception is rethrown.

This route is the ninth UID0003YT caller, `0x45d5d6`. UID0003YS itself has exactly one incoming call at `0x45d187`, no data xrefs, and no VA/RVA/raw-offset pointer route. Its compiler-EH caller placement and exact two-pointer range ABI reject a developer-authored `RankingCategoryRecord` method: this class owns the nested member and per-record lifetime semantics, while UID0000BK owns the outer range operation.

The formal declaration remains `std::vector<RankingUserEntry> m_userEntries`; no raw begin/end/capacity fields, range helper declaration, or binary helper body is added. UID0003YS is `RECONSTRUCTABLE:FALSE` with blank emitter/CPP/H, and this class remains `93/95` with its current formal source intact. Runtime equivalence requires the selected compiler to regenerate equivalent nested-member cleanup for partially constructed outer ranges.

## Historical Source-Shape Corrections

- The earlier draft placed the full declaration in formal CPP and left formal H blank. That was useful reconstruction scaffolding but inverted the source/header boundary. The declaration now lives in formal H, while CPP carries only child method definitions.
- The earlier explicit `short m_padding02` preserved the observed offset but represented compiler alignment as a semantic field. Natural 32-bit C++ alignment produces the same `m_categoryId +0x04` offset without an invented source member.
- The earlier `m_userEntriesBegin`/`m_userEntriesEnd`/`m_userEntriesCapacity` fields described physical compiler storage. Append, growth, reset, clone, and destructor behavior prove they are one period-correct `std::vector<RankingUserEntry>`; the three-slot representation remains documented as physical evidence.
- The earlier UID0002KA formal body `m_userEntriesEnd = m_userEntriesBegin` preserved the exact optimized lowering but was not developer-facing source and did not compile against this class declaration. It is superseded by `m_userEntries.clear()` while retained as physical evidence.
- Historical selected-user-index wording for `+0x268` is disproved by parser writes and footer paint consumption; the field is `m_localPlayerRank`.
- The earlier UID0002K6 endpoint `0x0045c01a`, const declaration, and raw-pointer-field method body were useful binary-shaped scaffolding but are superseded. The exact body includes the complete `retn 4` through `0x0045c01a`, so the half-open endpoint is `0x0045c01b`; a const method cannot naturally return the observed mutable row pointer without an unsupported cast.
- Earlier target links used the exclusive end `0x0045bf83`. Exact item and byte evidence proves [UID:0002K2][0x0045bf80-0x0045bf84.RankingCategoryRecordGetStateCode](by-memory/0x0045bf80-0x0045bf84.RankingCategoryRecordGetStateCode.md) ends at `0x0045bf84`, including its one-byte return.
- The 2026-06 draft `RankingDateTimeParts` declaration and `CopyStartTimeParts(out)`/`CopyEndTimeParts(out)` methods were useful byte-preserving scaffolding, but they are superseded. Live IDA already contains the exact 36-byte `tm` UDT, and the explicit output argument is MSVC x86 structure-return lowering for authored `tm GetStartTime() const` / `tm GetEndTime() const` methods.
- The old `reserved0/reserved1/reserved2` names are superseded by `tm_wday/tm_yday/tm_isdst`. This correction does not claim those values are initialized or consumed in the ranking workflow; the packed setters leave them untouched and paint uses only the first six fields.
- `<time.h>` is the selected source include for unqualified `tm` in the period-appropriate MSVC declaration. `<ctime>` is not a competing current recommendation.

## Evidence Notes

- 2026-05-25 IDA MCP confirms every method start listed above as a normal function.
- 2026-05-27 IDA MCP confirms three additional function starts in the same record range: `0x0045c050`, `0x0045c100`, and `0x0045c1e0`.
- Caller evidence shows these disabled helpers are still live in the ranking cluster: `GetListIndex` is called from `RankingEventListPane::HandleEvent` at `0x0045b511`, start/end copy helpers are called from `RankingUserListPane::OnPaint` at `0x0045f4fe` and `0x0045f56f`, `GetTitleText` is used by both event/reward/user drawing paths, `GetUserEntryAt` is called from `RankingUserListPane::OnPaint`, and `ResetUserEntries` is called from the category-selection/update path at `0x004594f7`.
- 2026-08-04 B007 live read-only MCP session `9081c1f3-bc94-49a3-a909-a60eafeb0a99` reconfirmed UID0002K6 as `[0x0045bfe0,0x0045c01b)`, size `0x3b`, with sole call at `0x0045f637`, no callees, signed count comparison, exact `0x4c` pointer arithmetic, and five-byte `0xcc` postpad through `0x0045c020`. The caller's `0..9` loop null-checks rows before consuming `rank/name/score` at `+0x04/+0x08/+0x48`.
- Fresh Gate2B prestate on 2026-08-04 corrected the UID0002K6 postpad's physical representation: `[0x0045c01b,0x0045c020)` is one existing physical item, size `5`, unnamed, untyped, `is_code:false`, `is_data:true`, containing `cc cc cc cc cc`, with blank comments and zero xrefs. It remains non-emitting alignment after the class method, so class ownership, the non-const declaration, and the method source are unchanged.
- 2026-06-16 C001 live IDA refresh reconfirmed all eleven function sizes and xrefs, including category-id use from dialog, event-list, reward, and user-list paths; setter calls from `0x0045c2a0` and `0x0045c560`; append from `0x0045cb10`; and reset from `0x004594d0`. C001 saved `RankingCategoryRecord_*` names for all eleven helpers in the IDB.
- Historical 2026-06-19 B015 evidence corrected [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md) to half-open range `0x0045c050-0x0045c0f9`: raw body `0xa9` bytes at PE raw `0x5b450`, SHA1 `6f8ad81d88a47803ddb555472dcad2896cfa0ce5`, full `c2 08 00`, then seven `0xcc` bytes. Its then-current `year/month/day/hour/minute/second` wording is now mapped exactly to `tm_year/tm_mon/tm_mday/tm_hour/tm_min/tm_sec`; the underlying writes remain unchanged.
- Historical 2026-06-20 B001 evidence corrected [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) to half-open range `0x0045c100-0x0045c1a9`: raw body `0xa9` bytes at PE raw `0x5b500`, SHA1 `5db36d68b861e1df28309949538868a3f61c2d40`, full `c2 08 00`, then seven `0xcc` bytes before `0x0045c1b0`. Its former custom-field wording is superseded by the same exact `tm_*` mapping. Direct callers remain `0x0045c4b3` and `0x0045c787`; no callee or pointer route was found.
- 2026-06-23 B001 current MCP session `80de0a67` resolved the raw setter starts at `0x0045c020`, `0x0045c030`, `0x0045c040`, `0x0045c1b0`, and `0x0045c1d0`. `lookup_funcs` reports no IDA function objects at those starts and `xrefs_to` reports zero inbound refs, but byte review proves complete field setter bodies with padding/successor boundaries. These children now carry first-draft C++, and the class declaration includes the five setter declarations. Completion/confidence are raised to `88/92` because the prior adjacent raw-helper blocker is closed without reverting the accepted `m_reservedLocalPlayerFooter[0x40]` correction.
- 2026-07-03 B003 callback sync rechecked current MCP session `b010_00032w_20260703` and repaired stale generated-output links for UID000428-UID00042C. The raw setter starts remain no-function/zero-xref bodies, but bounded disassembly and unique byte signatures confirm the same source-shaped setters and clean padding fences; their current child pages are the RankingCategoryRecord setter files, not stale MapPane generated-output filenames. [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md) is now the non-emitting sixteen-child split/index aggregate while this class declaration and exact child pages provide source output through [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md).

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md)
- [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md)
- [UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md)
- [UID:0003YV][0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage](by-memory/0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md)
- [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md)
- UID000428 [0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex](by-memory/0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex.md)
- UID000429 [0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId](by-memory/0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId.md)
- [UID:0004YY][0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode](by-memory/0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode.md)
- UID00042B [0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText](by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md)
- UID00042C [0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount](by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md)

## Changes

- 2026-08-14 B003 UID0003WT private-access callback:
  - Preserved `94/95`, UID0000MZ owner/emitter routing, position `0`, exact natural layout, and all UID0003WS content.
  - Confirmed the accepted narrow friend declaration was already present at the exact formal-H location and documented UID0003WT's rank/score/loaded-id/state writes, absent-metadata state, `0x4c` append order, total commit, and complete no-reserved-tail result.
  - Added no public setter, extra method, duplicate declaration, or physical-layout change.

- 2026-08-14 B001 UID0003WS private-access callback:
  - Preserved `94/95`, UID0000MZ owner/emitter routing, position `0`, exact layout, partial constructor, and all unrelated history.
  - Added the exact narrow `friend class RankingCategoryCollection;` declaration in formal H so UID0003WS can express its proved private page-metadata stores without broadening the public API.
  - Documented the four-field optional-local write set, absent-block baseline, complete no-reserved-tail evidence, and unchanged `0x2b0` layout/lifetime consequences.

- 2026-08-14 B005 UID0003WR accepted constructor callback:
  - Raised completion from `93` to `94` while retaining confidence `95`, owner/emitter UID0000MZ, and position `0`.
  - Added the exact inline formal-H default constructor for total count `0` and loaded-category/rank/score `-1` sentinels, preserving default vector lifetime and the implicit copy constructor.
  - Added the shared `0x00610bb0` bytes/hash/two-xref proof and explicitly preserved the primitive, `tm` tail, title tail, and reserved-footer uninitialized spans.

- 2026-08-06 B002 UID0003YU range-copy relationship:
  - Added the exact `0x45d6a8` element-copy relationship, `0x2b0` range stride, nested-vector deep-copy consequence, partial-range rollback route, and separation between record element semantics and collection-vector ownership.
  - Preserved class `93/95`, UID0000MZ owner/emitter, the complete formal H declaration, `[[CHILDREN]]` CPP routing, and the implicit-special-member source shape; no target range method or helper body was added.

- 2026-08-06 B007 UID0003X4 implicit-copy source closure:
  - Added the exact implicit-copy body identity, fixed-versus-nontrivial member split, all five uses, nested-vector/EH behavior, negative source-shape evidence, and class-owned regeneration route.
  - Preserved class `93/95`, the complete formal H declaration, `[[CHILDREN]]` CPP routing, natural alignment, vector layout, method inventory, and all prior lifetime/history detail; no explicit copy declaration/body was added.

- 2026-08-05 B007 UID0003YR header-order callback:
  - Preserved class metadata at `93/95`, owner/emitter UID0000MZ, and every existing formal CPP/H line.
  - Set emitter position `0` so the complete `RankingCategoryRecord` declaration precedes [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) and its `std::vector<RankingCategoryRecord> m_records` member under the intended C++03 toolchain model.
  - This is an emission-order correction only; it adds no duplicate type, method, or container code.

- 2026-08-05 B005 UID0003YS external-lifetime callback:
  - Added the exact `0x2b0` outer range walk, `+0x258` nested-member receiver, ninth UID0003YT route, partial-construction rollback/free/rethrow cause, owner separation, and no-standalone-helper source rule.
  - Preserved class `93/95`, UID0000MZ owner/emitter, `std::vector<RankingUserEntry> m_userEntries` formal declaration, and all existing method/layout/history content.

- 2026-08-04 B007 UID0003YT class-lifetime callback:
  - Preserved class metadata at `93/95` and the existing formal H declaration.
  - Added the exact 99-byte vector-teardown lowering, small/large allocation paths, double-underscore invalid-parameter callee, free/triplet poststate, nine lifetime routes, `sub_45C2A0` EH-tail ownership, reset-versus-release distinction, and no-standalone-helper source boundary.

- 2026-08-04 B005 UID0002KA class-support implementation:
  - Preserved class metadata at `93/95`, formal `[[CHILDREN]]` CPP, exact formal H declaration/member layout, and UID0000MZ owner/emitter routing.
  - Expanded `ResetUserEntries` with exact range/bytes, `std::vector::clear()` lowering, capacity preservation, destructor contrast, parser/paint rank semantics, sole-caller `void` proof, and source/header placement.
  - Historicalized the direct raw-vector source body and selected-user-index interpretation without deleting their useful lowering provenance.
- 2026-08-04 B007 C30 Gate2B-prestate correction:
  - Added the exact existing five-byte data-item model to UID0002K6 endpoint/postpad evidence: one unnamed, untyped, non-code item at `[0x0045c01b,0x0045c020)`, with five CC bytes, blank comments, and zero xrefs.
  - Preserved class metadata, owner/emitter routing, formal CPP/H, method behavior, source placement, and all unrelated class evidence; the postpad remains no-source alignment.

- 2026-08-04 B007 UID0002K6 source-quality callback:
  - Preserved class metadata at `93/95`, owner/emitter UID0000MZ, formal CPP `[[CHILDREN]]`, and every unrelated class/layout conclusion.
  - Replaced the formal H declaration with non-const `RankingUserEntry* GetUserEntryAt(int index);`, corrected the child link to half-open endpoint `0x0045c01b`, and added the signed upper-bound-only/null/mutable-pointer contract plus sole `0..9` paint caller.
  - Historicalized the old const declaration, raw begin/end method body, stale endpoint, and defensive lower-bound alternatives instead of deleting the earlier compiler-layout evidence.

- 2026-08-02 B009 UID0002K3 standard-`tm` source-quality callback:
  - Raised the class from `90/93` to `93/95` while preserving owner/emitter UID0000MZ, `[[CHILDREN]]`, all unrelated record methods/layout evidence, and the existing source route.
  - Replaced the custom date-time source model with standard `<time.h>` `tm m_startTime` / `tm m_endTime` members and source-authored by-value `GetStartTime()` / `GetEndTime()` declarations; exact child pages continue to own their CPP definitions.
  - Reconciled the packed setters with direct packet component stores into the first six `tm_*` fields, preserved the untouched trailing fields, and retained the former `RankingDateTimeParts`/explicit-output form as an explicitly superseded historical hypothesis.

- 2026-07-31 B009 UID0003WU record relationship:
  - Added exact inlined `GetCategoryId()`/`SetStateCode(1)` evidence from the reward-claim status response.
  - Preserved class `90/93`, formal CPP/H, naturally aligned layout, storage-helper split, reserved-footer correction, and all earlier source-shape history.
- 2026-07-30 B007 UID0002K2 ordinary implementation callback:
  - Raised the class from `88/92` to `90/93` after correcting formal H/CPP placement, natural alignment, record-owned `std::vector<RankingUserEntry>` source shape, and the exact four-byte GetStateCode range/state behavior.
  - Preserved the earlier explicit-padding and three-pointer declaration as historical compiler-layout evidence rather than current developer-facing source.
- 2026-06-23 B001 accepted raw setter implementation:
  - Before: `86/90`, with an "Adjacent Raw Setter Gaps" section and no setter declarations for `0x0045c020/30/40/1b0/1d0`.
  - Changed to: `88/92`; added setter declarations to the class C++ block and replaced the gap section with accepted exact child inventory.
  - Summary/evidence: current MCP session `80de0a67` proved no IDA function objects and no inbound xrefs for all five starts, but byte review established complete raw field setters and clean boundaries. Created UID000428 [0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex](by-memory/0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex.md), UID000429 [0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId](by-memory/0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId.md), [UID:0004YY][0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode](by-memory/0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode.md), UID00042B [0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText](by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md), and UID00042C [0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount](by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md), each with first-draft C++. Preserved the B005 correction that `+0x26c-+0x2ab` remains `m_reservedLocalPlayerFooter[0x40]`.

- 2026-07-03 B003 accepted UID0000Y9 support sync:
  - Updated UID000428-UID00042C references from stale MapPane generated-output filenames to the current RankingCategoryRecord setter pages.
  - Evidence: current MCP session `b010_00032w_20260703` reconfirmed the five starts as no-function/zero-xref raw setters with source-shaped bodies, clean padding, and RankingCategoryRecord field ownership. [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md) is now documented as the non-emitting sixteen-child aggregate/index; the class declaration and exact child pages remain the source output route.

- 2026-06-20 B001 accepted K8 implementation:
  - Updated the `SetEndTimeFromPackedDateTime` inventory range/link to `0x0045c100-0x0045c1a9`.
  - Added the accepted source role: `RankingCategoryRecord::SetEndTimeFromPackedDateTime(int packedDate, int packedTime)` initializes the visible end date/time fields and leaves reserved date-time dwords untouched.
  - Evidence: corrected raw range includes the final `00` byte of `retn 8`; parser callers are `0x0045c4b3` and `0x0045c787`; no callees or pointer route were found; the old final-C++ blocker is superseded by the current class declaration and `RankingDateTimeParts` layout evidence.
- 2026-06-19 B015 accepted K7 implementation:
  - Updated the `SetStartTimeFromPackedDateTime` inventory range/link to `0x0045c050-0x0045c0f9`.
  - Added the accepted source role: `RankingCategoryRecord::SetStartTimeFromPackedDateTime(int packedDate, int packedTime)` initializes the visible start date/time fields and leaves reserved date-time dwords untouched.
  - Evidence: corrected raw range includes the final `00` byte of `retn 8`; parser callers remain `0x0045c49c` and `0x0045c770`; no callees or pointer route were found. Paired [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) now has the symmetric endpoint/source-quality implementation.
- 2026-06-18 B005 RankingUserListPane source-quality correction:
  - Before: the class declaration and layout notes modeled `+0x26c-+0x2ab` as proved `wchar_t m_localPlayerName[32]` storage.
  - Changed to: `unsigned char m_reservedLocalPlayerFooter[0x40]`, with evidence explaining that the tail is copied/preserved but not read by `RankingUserListPane::OnPaint`.
  - Evidence: B005 checked parser/deep-copy/paint evidence and found footer rank/score at `+0x268`/`+0x2ac`, while the displayed footer name is constructed from global `word_69BEE0` through `0x005a2dc0`; no checked parser writes the `+0x26c` tail and the paint method does not read it.
- 2026-06-17 B002 source-quality execution:
  - Added first-draft class/type declaration C++ for `RankingDateTimeParts`, `RankingUserEntry`, and `RankingCategoryRecord`, with the `[[CHILDREN]]` marker after the class declaration so method definitions from exact child pages emit outside the class body.
  - Evidence: B002 resolved the getter/reset fields, `RankingDateTimeParts` order, `RankingUserEntry` row shape, `m_localPlayerRank`, user-entry vector ownership, and the split of [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) into collection-owned and record-owned generated/container helper children.
- 2026-06-16 B002 RankingCategoryCollection support refresh:
  - Before: `85/89`, with enough record method evidence to clear the gate but still carrying broad title/tail wording.
  - Changed to: `86/90`, preserving route through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
  - Evidence: B002 row parser and user-list paint review resolved `+0x254` as total count, `+0x264` as loaded/current category id, `+0x268` as local-player rank, and `+0x2ac` as local-player score/value. B005 later corrected the `+0x26c-+0x2ab` name-buffer interpretation to copied/reserved footer tail storage because the displayed name comes from global `word_69BEE0` rather than the record field. Remaining record uncertainty is limited to original field spellings and detailed source type declarations, not layout ownership.
- 2026-06-16 B002 AppendUserEntry source-quality refresh:
  - Metadata unchanged at `86/90`.
  - Evidence: [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md) now documents the `RankingUserEntry` append path at `+0x258/+0x25c/+0x260`, row fields `categoryId`, `rank`, `name[32]`, and `score`, generated growth-helper boundary [UID:0003X1][0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth](by-memory/0x0045d1b0-0x0045d317.RankingUserEntryVectorInsertWithGrowth.md), source-facing `void AppendUserEntry(const RankingUserEntry& entry)` interpretation, and rejection of broad collection/file ownership. Final C++ remains blocked by final record-vector abstraction/member spelling, not by method ownership or score.

- 2026-06-05: Raised from `82/86` to `84/88` after live IDA reconfirmed all eleven method starts/caller sets, the category parser and ranking-row parser relationships, the 688-byte record stride, and the 76-byte user-entry vector behavior. Removed recovered-output status wording and kept final C++ blank under the 95/95 gate.
- 2026-06-16 C001 IDA/name refresh:
  - Before: `84/88`, just below the strict direct-parent completion gate for [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md).
  - After: `85/89`, preserving owner/emitter route through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) and final C++ blank.
  - Evidence: live IDA reconfirmed all eleven method starts/sizes, caller sets, record stride, user-entry vector behavior, date/time copy/set offsets, and row paint consumers; C001 saved the eleven `RankingCategoryRecord_*` function names. Final C++ remains blocked by source-facing date/time and `RankingUserEntry` declarations rather than by ownership.
- 2026-05-31: Marked the class as reconstructable and attached it to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md) after the method range was split into exact by-memory children.
  - Before: class page had strong method/layout evidence but validator autogen metadata was blank.
  - After: `RECONSTRUCTABLE:TRUE` with the file parent set, while final C++ remains blank because field/type names and source declarations are not at the 95+ final-source threshold.
  - Evidence: IDA MCP reconfirmed all eleven method starts, live callers, 688-byte record stride in collection parsers, and 76-byte user-entry operations.
- 2026-05-30: Grading changed from `0/0` to `80/84`.
  - Before: page documented method boundaries, layout offsets, live disabled/generated omissions, and caller evidence but remained unevaluated.
  - After: score reflects documented accessors, packed date/time setters, title/user-entry vector access, append/reset helpers, layout notes, and active generated-source omissions.
  - Evidence: IDA notes confirm all listed function starts, live callers from ranking event/user-list/category paths, 688-byte record stride, 76-byte user-entry stride, and links to [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md).
- 2026-05-27: Changed the method inventory from eight methods to eleven methods. Added the missing start/end packed date-time setters and user-entry append helper after IDA function enumeration/decompilation confirmed `0x0045c050`, `0x0045c100`, and `0x0045c1e0` are live `RankingCategoryRecord` functions inside the already documented aggregate range.
