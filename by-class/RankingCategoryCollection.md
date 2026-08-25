*** UID:0000BK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <windows.h>

#include "MemoryMan.h"
#include "RankingDialog.h"
#include "PacketBuffer.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include <vector>

class RankingCategoryCollection
{
public:
    RankingCategoryCollection();

    void ParseCategoryListResponse(const unsigned char *packet);
    void ParseInitialCategoryPageResponse(const unsigned char *packet);
    void ParseRankingRowsResponse(const unsigned char *packet);
    void ApplyRewardClaimStatusResponse(const unsigned char *packet);

    void SetSelectedCategoryId(int categoryId);
    int GetCount() const;
    int GetSelectedCategoryId() const;
    RankingCategoryRecord *GetSelectedRecord() const;
    RankingCategoryRecord *GetByIndex(short index) const;

private:
    std::vector<RankingCategoryRecord> m_records;
    int m_selectedCategoryId;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingCategoryCollection

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md)
- Related storage helpers: [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) split/index, with collection-owned children [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md), [UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md), and [UID:0003YU][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md).
- Parent range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Confidence: very strong for collection identity, embedded offset, packet subcommand dispatch, child ranges, record/user-entry strides, ownership, the standard-vector source member, implicit destructor, and source/header channel placement; strong for original source names because names are descriptive rather than symbol-proven.
- C++ reconstruction: formal H uses `std::vector<RankingCategoryRecord> m_records`, declares the source-ready category-list and initial-category-page parsers exactly once, and relies on the implicit class destructor. Formal CPP owns the exact compile-visible Win32 conversion, `MemoryMan.h`, `RankingDialog.h`, and `PacketBuffer.h` dependencies before `[[CHILDREN]]`, so both source-ready parser children regenerate the observed MemoryMan wrapper route without duplicating compiler-generated container support.
- Score: `93/95`, unchanged. The category-list parser, initial-category-page parser, and compile route are closed; other class children and stripped original spellings retain the bounded completion/confidence caps.

## Class Purpose

`RankingCategoryCollection` is a collection embedded in `RankingDialog`. It owns all ranking category/event records through `std::vector<RankingCategoryRecord> m_records`, tracks the selected category id, parses ranking category and ranking-page packet payloads, and relies on normal record/vector lifetime to release each record's nested user-entry storage.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingCategoryCollection` | `0x0045c260-0x0045c281` | Default-constructs the physical begin/end/capacity representation of `m_records`. IDA does not show a selected-category-id write at this address. |
| implicit `~RankingCategoryCollection` | [UID:0003WQ][0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk](by-memory/0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk.md) and [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md) | Normal `m_records` lifetime compiles into a five-byte destructor tail jump and 133-byte vector teardown. Neither binary helper is a declared source method or emitter. |
| `ParseCategoryListResponse` | `0x0045c2a0-0x0045c556` | Opcode `0x7d` subcommand `1`; clears existing records and parses category metadata/title records. |
| `ParseInitialCategoryPageResponse` | `0x0045c560-0x0045cb0a` | Opcode `0x7d` subcommand `3`; parses the category list, selected category id, optional local-player metadata, initial user rows, and total count. |
| `ParseRankingRowsResponse` | `0x0045cb10-0x0045cdb4` | Opcode `0x7d` subcommand `2`; validates the selected category id, clears/appends user rows, and stores local-player/total metadata. |
| `ApplyRewardClaimStatusResponse` | [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md) | Opcode `0x7d` subcommand `6`; reads BE32 category id at `+0x02`, returns on zero status at `+0x06`, and sets the first matching record state to claimed (`1`). Source-ready formal CPP is owned by the exact child. |
| `SetSelectedCategoryId` | `0x0045ce30-0x0045ce3d` | Stores selected category id at collection offset `+0x0c`. |
| `GetCount` | `0x0045ce40-0x0045ce57` | Source uses `m_records.size()`; the binary lowers this to begin/end subtraction divided by `0x2b0`. |
| `GetSelectedCategoryId` | `0x0045ce60-0x0045ce64` | Returns selected category id at collection offset `+0x0c`. |
| `GetSelectedRecord` | `0x0045ce70-0x0045ceab` | Finds the category record whose id matches the selected category id. |
| `GetByIndex` | [UID:0003WZ][0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex](by-memory/0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex.md) | Accepts signed `short index`, rejects negative/out-of-range values, and returns `&m_records[index]`; the binary result is a `0x2b0`-stride pointer. |
| `RankingCategoryRecordVectorInsertWithGrowth` | [UID:0003X0][0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth](by-memory/0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth.md) | Reviewed non-emitting 605-byte MSVC outer-vector growth/insert specialization generated by ordinary `m_records` appends. Descriptive binary name only; no source declaration or definition. |
| `RankingUserEntryVectorInsertWithGrowth` | `0x0045d1b0-0x0045d317` | Source-declared/generated-binary `0x4c` user-entry vector insert/growth helper; direct layout support is [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)/[UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md). |
| `RankingUserEntryCopyRange` | `0x0045d320-0x0045d36c` | Copies contiguous `0x4c` user-entry rows. |
| `RankingUserEntryVectorClone` | `0x0045d370-0x0045d419` | Initializes and deep-copies a user-entry vector. |
| implicit `RankingCategoryRecord` copy construction | [UID:0003X4][0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep](by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md) | Reviewed non-emitting 216-byte element-copy lowering generated by ordinary `m_records` operations; exact fixed-member copy plus nested `m_userEntries` deep copy, with no helper declaration/API/body. |
| `RankingCategoryRecordRangeUserEntryCleanupFunclet` | `0x0045d500-0x0045d528` | Compiler EH cleanup funclet adjacent to this range; document/ignore, do not emit as a method. |

## Category-List Response Source Contract

[UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md) is now source-ready in `NexusTK/ui/dialogs/RankingDialog.cpp`:

- It clears `m_records` first while retaining outer capacity and destroying each prior record's nested user-entry vector.
- It narrows the big-endian UInt16 count at `packet + 2` to signed `short` and uses a signed 16-bit cursor beginning at `4`.
- Each record reads category id, start date/time, end date/time, signed-char state, unsigned-byte title length, and exact title payload in one 22-byte fixed header plus payload.
- Title conversion uses `CP_ACP`, explicit input length, and wide capacity `256`; no packet bounds, encoding, or conversion-error branch is added.
- An automatic [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) carries the exact partial constructor baseline, receives the six existing setter operations, and is appended with ordinary `m_records.push_back`.
- Failures retain an empty collection or the successfully appended prefix. Only the individual vector growth operation has its standard strong guarantee.

The CPP preamble therefore needs `<string.h>` for `memmove` and `<windows.h>` for `CP_ACP`/`MultiByteToWideChar`, followed by the existing project headers. [UID:0003YK][0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers](by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md) owns the shared UInt16BE and UInt32BE declarations through `PacketBuffer.h`; no feature-local redeclaration is valid.

The source remains one ordinary class method. UID0003X4 deep copy, UID0003X0 growth, nested-vector destruction, the external cleanup chunks, security-cookie support, and range-check failure remain compiler-generated and non-emitting.

## Initial Category Page Response Source Contract

[UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) is source-ready as the combined opcode `0x7d` subcommand `3` parser. Its exact formal definition belongs to that child and emits through this class into `NexusTK/ui/dialogs/RankingDialog.cpp`; the existing formal H declaration here remains the sole declaration.

- The method first clears `m_records`, preserving outer capacity while destroying prior records' nested row storage. It narrows the UInt16BE category count to signed `short` and advances a signed 16-bit cursor from packet offset `4`.
- Every category consumes BE32 id, packed start date/time, packed end date/time, signed state, unsigned title length, and title bytes. Title conversion uses `MemoryMan::MemmoveWrapper`, an explicit narrow terminator, `MultiByteToWideChar` with `CP_ACP` and capacity `256`, and an indexed wide terminator before the existing record setters and ordinary append.
- Partial record construction supplies the exact empty-row, total-zero, and loaded-category/local-rank/local-score `-1` baseline. The parser does not whole-zero the object or initialize unrelated `tm` tail fields and reserved bytes.
- After rebuilding categories, the method reads the selected category id and searches only the rebuilt vector. A miss returns with the refreshed category prefix intact and leaves the prior collection selection and all page state uncommitted. A match stores `m_selectedCategoryId`, clears the selected row vector without freeing capacity, and resets local rank to `-1`.
- The optional-local flag is a signed `char`; only values `1..127` enter the block. The block reads BE32 rank, BE32 score, and signed state, then writes exactly loaded category id, score, rank, and state. It does not write `m_reservedLocalPlayerFooter[0x40]` or any byte at record offsets `+0x26c..+0x2ab`.
- Row count is UInt16BE narrowed to signed `short`; a negative value skips appends and leaves the cursor at the total field. Each row reads unsigned name length/text, performs the same bounded temporary conversion, stores category id/rank/name/score into a `0x4c` `RankingUserEntry`, and appends normally. Final BE32 total is committed only after all requested rows append.
- There are no packet-null, packet-length, count, conversion-result, or rollback guards. Allocation, conversion, secure-copy, and range-check failures propagate. Prior destructive work and completed appends remain visible; only an individual `std::vector` growth operation retains its library guarantee.

The direct writes to private record page metadata are legal through the exact narrow `friend class RankingCategoryCollection;` declaration owned by [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md). Scalar BE helpers remain owned by [UID:0003YK][0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers](by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md), while ordinary vector operations regenerate UID0003X0/UID0003X4 and their EH/lifetime support. No raw storage helper, cleanup funclet, cookie path, or allocator lowering is authored as an additional class method.
| `RankingCategoryRecordVectorDestroy` | [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md) | Reviewed non-emitting outer `std::vector<RankingCategoryRecord>` teardown specialization. The descriptive name is documentation/IDA terminology; formal CPP/H is blank because `m_records` and implicit destruction regenerate it. |
| `RankingCategoryRecordRangeDestroyUserEntries` | [UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md) | Reviewed non-emitting compiler EH rollback for partial category-record vector growth; collection semantic owner, false/blank child, no source declaration or definition. |
| `RankingCategoryRecordRangeCopyConstructDeep` | [UID:0003YU][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md) | Reviewed non-emitting 118-byte uninitialized range-copy lowering generated by ordinary `m_records` growth. It deep-copy constructs a half-open record range through UID0003X4, returns the destination end, and cleans the constructed prefix on exception; the descriptive helper name is documentation/IDA terminology, not a source API. |

## Ranking Rows Response Source Contract

[UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) is source-ready as opcode `0x7d` subcommand `2`. Its complete formal definition belongs to that exact child and emits through this class into `NexusTK/ui/dialogs/RankingDialog.cpp`; the existing `void ParseRankingRowsResponse(const unsigned char *packet);` in formal H remains the sole declaration.

- The BE32 response category id must equal `m_selectedCategoryId`; otherwise the method returns without mutation. The method then searches `m_records` for the matching `0x2b0` `RankingCategoryRecord` and returns without mutation if no record exists.
- A found record is prepared with `ResetUserEntries()`, which clears logical rows without freeing vector capacity, followed by the explicit `m_localPlayerRank = -1` baseline.
- The optional-local flag at packet offset `+6` is a signed `char`; only positive values enter the metadata block. BE32 rank at `+7`, BE32 score at `+11`, loaded category id, and signed state at `+15` are committed in observed order. The parser does not write `m_reservedLocalPlayerFooter` or any byte at record offsets `+0x26c..+0x2ab`.
- When optional metadata is absent, rank remains `-1` while loaded id, state, reserved tail, and local-player score retain their previous values. This asymmetric state is deliberate retail behavior rather than a missing initialization.
- The UInt16BE row count and packet cursor are narrowed to signed `short`. Each row uses an unsigned-byte name length, `MemoryMan::MemmoveWrapper`, explicit narrow termination, `MultiByteToWideChar(CP_ACP, ...)`, explicit wide termination, a secure 32-WCHAR copy, and exact `0x4c` `RankingUserEntry` category/rank/name/score layout before ordinary `AppendUserEntry`.
- The final BE32 total is committed only after all rows append. No packet-length, null, row-count, name-length, conversion-result, or rollback guards exist; a failure preserves prior reset and completed appends.

The paired `RequestRankingPage` sends the same category id plus one-based inclusive bounds `10 * page + 1` through `10 * (page + 1)`. The exact method body is `[0x0045cb10,0x0045cdb4)`, SHA256 `B1C3573A44D5F534DB1A68FDBFED5612219556051A811DA63AE0F359DC265677`, with only the dispatcher call at `0x004592ca`. Its six-byte predecessor and twelve-byte successor `CC` pads remain separate non-emitting data. Packet readers, MemoryMan, Win32 conversion, secure copy, record append/reset, and ordinary vector operations remain dependencies; range-check, cookie, vector-growth, copy, and EH lowerings are not added as class APIs.

## Evidence Notes

- `RankingDialog` embeds this collection at offset `+0x26c` and calls it for selected category and packet request state.
- IDA shows packet handler `0x00459210` dispatching opcode `0x7d` subcommands `1`, `2`, `3`, and `6` to this class's parser/update methods.
- `RankingEventListPane` uses the collection for event/category display and click selection.
- `RankingRewardInfoDialog` uses the selected category id when requesting reward information.
- The paired [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md) sends opcode `0x7d`, subcommand `6`, and the selected BE32 category id. [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md) consumes the seven-byte response and updates collection-owned record state.
- UID0003WU proves source calls to `GetCount()`, `GetByIndex(short)`, `RankingCategoryRecord::GetCategoryId()`, and `RankingCategoryRecord::SetStateCode(1)`. The direct binary pointer walk/store is compiler lowering for those ordinary source APIs.
- `GetByIndex` uses a sign-extended 16-bit argument in the live prototype and signed checks. The former `int index` declaration was source-inaccurate and is historicalized by this callback.
- 2026-06-04 live IDA MCP reverified every method/helper range listed above, the constructor call at `0x00458695`, destructor calls/unwind at `0x00458973`, `0x00459866`, and `0x005fa14f`, and packet-handler calls at `0x00459243`, `0x00459276`, `0x004592ca`, and `0x004592e4`.
- 2026-06-23 B001 current MCP session `80de0a67` reconfirms `0x0045c260` as a modeled constructor that writes only the begin/end/capacity pointers, not selected id; reconfirms packet-handler calls to parse/update methods for opcode `0x7d` subcommands `1`, `2`, `3`, and `6`; and keeps parser/helper body emission on exact by-memory children.
- The source declaration is safe in formal H because `m_records` exactly explains the three-dword vector storage, `m_selectedCategoryId` explains `+0x0c`, and the method inventory is stable. Formal CPP deliberately routes exact child definitions rather than hand-porting parser bodies or vector growth/copy/destruction helpers.

## Outer Category Vector And Implicit Destructor

The physical collection fields at `+0x00/+0x04/+0x08` are the MSVC representation of one source-authored `std::vector<RankingCategoryRecord> m_records`, not three independent pointers. The constructor at `0x0045c260` zeroes those words because it is default-constructing the vector. `GetCount()` and `GetByIndex(short)` expose normal source container operations while preserving the exact pointer-difference, `0x2b0` stride, signed-negative check, and null-on-invalid binary behavior.

The compiler-generated lifetime route is exact. [UID:0003WQ][0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk](by-memory/0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk.md) tail-jumps to [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md). The teardown walks records at stride `0x2b0`, destroys each `m_userEntries` at `+0x258`, applies the MSVC small/large allocation validation path, frees outer storage, and clears the vector triplet. Target and thunk body hashes are `BD68BC2529D22C1E3F240894411081A291B663A38B45EC1B1130BB149034C24D` and `BF61252F1E61B859B1994B42177DBE6C9E3859519FCFEA28A27E51A8FC5F11D4`.

No explicit destructor declaration or definition belongs in the recovered source: `m_records` gives `RankingCategoryCollection` the required implicit destructor. UID0003YR and UID0003WQ remain semantically owned by this class but are non-reconstructable, non-emitting, and blank in formal code. Their source-facing names describe the binary for documentation/IDA only. The previous raw pointer fields and explicit destructor declaration are retained as corrected historical reconstruction, not current source shape.

The header emission order is intentional. [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) emits at position `0`, and this class emits at position `10`, so `RankingCategoryRecord` is complete before `std::vector<RankingCategoryRecord>` is instantiated under the intended mid-2000s C++03 source/toolchain model.

## Outer Category Vector Growth And Insert Specialization

[UID:0003X0][0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth](by-memory/0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth.md) is semantically owned by this class because both direct callers append stack-built records to `m_records`. [UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md) calls the slow path at `0x45c502` after its fast per-record copy at `0x45c4f1`; [UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) mirrors that branch at `0x45c7dc` after fast copy `0x45c7cb`. No data route, callback, vtable slot, or non-parser caller exists.

The 605-byte specialization uses exact `0x2b0` record stride, one-half growth with required-size selection, direct or 32-byte-aligned large allocation, inserted-record-first deep copy, prefix/suffix construction for middle insertion, and old-record `m_userEntries` destruction at `+0x258` before old storage is freed and the new vector triplet is committed. Its post-return exception tail destroys the partially constructed range through UID0003YS, frees failed outer storage through UID0001ZE, and rethrows, preserving the strong guarantee.

The source-visible operation is simply the parser's append to `std::vector<RankingCategoryRecord> m_records`. The existing formal H declaration is therefore already the correct human-written source cause and remains exact. Formal class CPP continues to route child methods through `[[CHILDREN]]`; it must not contain a helper definition, allocator lowering, raw begin/end/capacity manipulation, or explicit EH cleanup.

UID0003X0 is consequently `94/95`, semantically owned by UID0000BK, `RECONSTRUCTABLE:FALSE`, non-emitting, and blank in CPP/H. This class remains `92/95` with its exact existing formal CPP/H, owner/emitter UID0000MZ, and emitter position `10`. Earlier wording that treated understood generated behavior as a source-declared helper is retained as corrected historical interpretation.

## Implicit RankingCategoryRecord Element Copy

The same `m_records` operations generate [UID:0003X4][0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep](by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md), the implicit copy constructor for each `RankingCategoryRecord` element:

- Its exact 216-byte, 57-instruction, one-block body copies record fixed spans `+0x000..+0x257` and `+0x264..+0x2af`, and deep-copy constructs only the source member `m_userEntries` at physical `+0x258/+0x25c/+0x260` through UID0003X3.
- Parser fast paths call it at `0x45c4f1` and `0x45c7cb`, advance `m_records` end only after success, then destroy the stack temporary's nested vector at `0x45c514` or `0x45c7ee`.
- UID0003X0 calls it at `0x45d07b` and `0x45d0a9` for inserted/end-path construction; UID0003YU calls it at `0x45d6a8` for each element in a half-open `0x2b0`-stride range. These five sites are the complete incoming code route.
- Outer-vector growth retains strong exception safety: nested copy failure prevents destination lifetime advance; partial ranges are destroyed through UID0003YS/UID0003YT, failed storage is released through UID0001ZE, and the exception is rethrown.
- The authored source is still only ordinary parser append/range behavior over `std::vector<RankingCategoryRecord> m_records`. No `RankingCategoryRecordCopyConstructDeep` member/helper API, explicit copy declaration, helper definition, raw triplet operation, or custom cleanup belongs in this class.
- UID0003X4 is `94/95`, semantically owned by UID0000BL, false/non-emitting, and blank in CPP/H. This collection remains its consumer and invocation source, while its existing formal H/CPP already provide the complete human-written source cause.

## Category-Record Uninitialized Range Copy

[UID:0003YU][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md) is the compiler-generated uninitialized range-copy specialization used by UID0003X0 while growing `m_records`. The only incoming code routes are the prefix call at `0x45d0c8` and suffix call at `0x45d0d9`. They pass half-open `[first,last)` source pointers and uninitialized destination storage around the newly inserted record; there is no callback, vtable, data, immediate, encoded-pointer, or gameplay-API route.

The 118-byte helper carries the destination vector context in ECX, consumes explicit first/last/destination pointers, returns with `retn 0Ch`, and returns the destination end. An empty range returns the original destination. Each iteration invokes UID0003X4 at `0x45d6a8`, advances both source and destination by exact record stride `0x2b0`, and records the new constructed end only after that deep copy succeeds. UID0003X4 copies the fixed record spans and deep-copy constructs `m_userEntries`, so this is not byte copying and cannot be represented safely with `memcpy`.

The helper also contains the compiler's strong-exception-safety route. Its SEH state tracks the constructed prefix; on failure the handler enters at `0x5fa330`, jumps through `0x5fa333` to UID0003X5, destroys nested user-entry vectors for the already constructed half-open range, performs the security-cookie check, and resumes unwinding. That lifetime machinery, the `0x2b0` stride, and the two prefix/suffix callers are all regenerated by ordinary C++03 `std::vector<RankingCategoryRecord>` growth over the existing `m_records` member.

Consequently, UID0003YU is `94/95`, semantically owned by this class, `RECONSTRUCTABLE:FALSE`, non-emitting, and blank in formal CPP/H. This class remains `92/95` with owner/emitter UID0000MZ, emitter position `10`, formal `std::vector<RankingCategoryRecord> m_records`, and the existing `[[CHILDREN]]` route. No explicit range-copy declaration, handwritten helper body, raw begin/end/capacity manipulation, explicit EH code, or standalone helper source file belongs in the recovered developer source. Earlier wording that called UID0003YU source-declared or source-emitting is retained as a corrected historical interpretation rather than current source shape.

## Category-Record Growth Exception Rollback

[UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md) is semantically owned by this class because its sole caller is the collection's category-record vector insert/growth helper. It is not a declared collection method. The 43-byte stdcall body receives a half-open range of partially constructed `RankingCategoryRecord` objects, advances by exact `0x2b0` record size, and calls the record-owned user-entry vector teardown at `record + 0x258` once per element.

The only target xref is `0x45d187` in the caller's post-return exception tail. That tail destroys the partial range, frees the failed destination allocation at `0x45d195`, then rethrows at `0x45d19e`. No data xref or VA/RVA/raw-offset pointer route reaches UID0003YS. Exact eleven-byte and five-byte `0xcc` fences isolate its body from adjacent helpers.

This is compiler-generated strong-exception-safety machinery for the class's source-level category-record vector operation. Authored source should retain ordinary `std::vector<RankingCategoryRecord>` behavior and the record's nested `std::vector<RankingUserEntry>` member rather than declare or define `RankingCategoryRecordRangeDestroyUserEntries`. The target is therefore `94/95`, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank CPP/H while retaining this class as semantic owner.

Direct UID0000BL ownership is rejected because this is an outer two-pointer range operation; UID0000BL owns each nested member's lifetime only. File-root ownership and owner `NONE` are also weaker than the exact collection operation. The descriptive helper name is documentation/IDA terminology, not an original-source-symbol claim.

## Selected-Record Page Reload Lifecycle

The collection and dialog divide the page-reload workflow cleanly. `RankingDialog::RequestRankingPage` obtains the record selected by `m_selectedCategoryId`, calls [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md), and then sends opcode `0x7d` / subcommand `2` with the selected category id and one-based interval `10 * page + 1` through `10 * (page + 1)`. The reset clears only the record-owned row vector's logical size and sets `m_localPlayerRank = -1`; it preserves vector allocation/capacity and the collection selection.

[UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) validates the response category against the collection's selected id, resolves the same record, repeats the logical clear and rank-sentinel reset, appends replacement `0x4c`-byte `RankingUserEntry` rows, and applies its page metadata and total. That primary page remains under B003's active assignment; its historical optional-footer interpretation is not a current source contract and B003 must incorporate the same proved no-reserved-footer correction in its callback. UID0003WS performs the equivalent setup for the combined initial list/page response and proves that its own optional-local block writes only loaded category id, local score, local rank, and state.

[UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md) constructs category records with a null user-vector triplet, local-player rank `-1`, local-player score `-1`, and total count zero before appending them to the collection. These shared states explain why later page parsers can clear and reuse record-local capacity without transferring row ownership to this collection page.

Historical wording that treated record `+0x268` as a selected-user field is rejected: collection `+0x0c` owns the selected category id, while record `+0x268` is the local-player rank consumed by `RankingUserListPane::OnPaint`.

## Reward-Claim Response Contract And Source Placement

- Request: six bytes, opcode `0x7d`, subcommand `6`, BE32 selected category id.
- Response: seven bytes, same opcode/subcommand/id plus one status byte at `+0x06`.
- Zero response status and unmatched category ids leave the collection unchanged. Nonzero status marks only the first matching record with state code `1`.
- The collection owns state lookup/mutation; `RankingDialog` owns request sending, dispatch, and post-response control refresh.
- The incomplete zero-member IDA type from catalog0379 is a prototype prerequisite only. It does not supersede this evidence-backed source declaration or authorize speculative concrete IDA layout mutation.

## 2026-07-31 Supervisor Catalog0379 IDA Type And Helper State

- Catalog entry `0379` records a supervisor-owned minimal IDA type prerequisite and selected-record helper identity. The transaction backup is `E:\NTK\Resources\NexusTK\backups\NexusTK.exe.pre-B007-UID0004YX-20260731_0424.i64`, SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, `143,192,665` bytes.
- Catalog0379 saved IDB SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, `143,192,707` bytes, saved `2026-07-31T04:26:38.9922636-04:00`, is the dated transaction checkpoint in MCP session `f608d7c2`.
- Authoritative current saved IDB SHA256 is `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143,192,751` bytes, saved `2026-07-31T06:21:13.3464834-04:00`, MCP session `f608d7c2`. Bounded read-only current-state verification preserves the same incomplete collection type and exact selected-record helper name/prototype/comment/range/xrefs/frame with no target-local drift.
- IDA now contains exactly one incomplete zero-member `RankingCategoryCollection` declaration. This is a pointer-prototype prerequisite only; it does not supersede, shrink, or independently prove the source-level four-field declaration documented on this class page.
- Exact helper `[0x0045ce70,0x0045ceab)` is now named `RankingCategoryCollection__GetSelectedRecord` and typed `RankingCategoryRecord *__thiscall(const RankingCategoryCollection *this)`.
- Its function-regular comment is exactly `Returns the selected ranking-category record whose category id matches the collection selection.` Address-regular, address-repeatable, and function-repeatable channels remain absent.
- The helper retains its 59-byte body, twelve incoming xrefs, return-only frame, callers, linear selected-id lookup, and null-return behavior. Historical `sub_45CE70` / `int __thiscall(int *this)` is retained only as the pre-catalog form.
- `RankingDialog` and `RankingCategoryRecord` remain incomplete IDA types. No concrete IDA collection layout, field/member mutation, score change, formal class change, parser rename, or source-route change was made.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md)
- [UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md)
- [UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md)
- [UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md)
- [UID:0003X5][0x0045d500-0x0045d528.RankingCategoryRecordRangeUserEntryCleanupFunclet](by-memory/0x0045d500-0x0045d528.RankingCategoryRecordRangeUserEntryCleanupFunclet.md)
- [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md)
- [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md)
- [UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md)
- [UID:0003YU][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md)

## Changes

### 2026-08-14 B003 UID0003WT selected-row response callback

- Preserved `93/95`, owner/emitter UID0000MZ, emitter position `10`, existing CPP include/children route, and the single formal-H method declaration.
- Added the exact stale-selection/no-match exits, clear-without-free and rank reset, signed optional metadata/count/cursor behavior, no-reserved-tail-write result, CP_ACP `0x4c` row construction, final-total commit, partial-success semantics, caller/request pairing, body identity, and compiler-helper exclusions.
- Kept the exact method body on UID0003WT and did not alter or duplicate UID0003WS work.

### 2026-08-14 B001 UID0003WS initial-page source callback

- Preserved `93/95`, UID0000MZ owner/emitter routing, emitter position `10`, the existing declaration, and every unrelated class/history conclusion.
- Added the complete signed count/cursor, category rebuild, selection commit, optional-local no-footer, row/total, helper, failure, and partial-success contract from the accepted UID0003WS report.
- Linked the direct private metadata stores to the narrow UID0000BL friendship and recorded UID0003WT's active B003 assignment instead of editing or prematurely accepting its legacy footer wording.

### 2026-08-14 B005 UID0003WR repaired source-shape callback

- Replaced the predecessor `<string.h>` dependency with `MemoryMan.h` while preserving `<windows.h>`, `RankingDialog.h`, `PacketBuffer.h`, and `[[CHILDREN]]` in exact compile order.
- Recorded `GetMemoryMan()->MemmoveWrapper` as the human source operation behind the parser's observed singleton/wrapper calls; direct CRT `memmove` is superseded for this child route.
- Preserved the existing formal H block, class metadata, owner/emitter route, and unrelated class detail.

### 2026-08-14 B005 UID0003WR category-list source callback

- Raised completion from `92` to `93` while retaining confidence `95`, owner/emitter UID0000MZ, and position `10`.
- Historically added `<string.h>` and `<windows.h>` to the formal CPP preamble before existing project headers and `[[CHILDREN]]`; the repaired callback above supersedes only the direct-CRT dependency with `MemoryMan.h`. Formal H remains unchanged and singular.
- Added the exact signed count/cursor, record wire layout, CP_ACP title conversion, partial constructor, ordinary append, successful-prefix failure, PacketBuffer dependency, and non-emitting compiler-helper dispositions.

### 2026-08-06 B002 UID0003YU uninitialized-range-copy route

- Reclassified the method inventory entry as a reviewed false/non-emitting compiler specialization rather than a source-declared helper.
- Added the exact two UID0003X0 prefix/suffix callers, UID0003X4 per-record deep copy, `0x2b0` source/destination stride, returned-end contract, constructed-prefix EH cleanup through UID0003X5, negative reachability, and standard-vector source regeneration.
- Preserved class `92/95`, owner/emitter UID0000MZ, emitter position `10`, and the exact existing formal CPP/H without adding a helper declaration or definition.

### 2026-08-06 B007 UID0003X4 implicit-element-copy route

- Replaced the generic helper inventory wording with the reviewed implicit-special-member disposition and added exact fixed/nested copy behavior, all five `m_records` uses, success/EH lifetime ordering, and no-helper-API source boundary.
- Preserved class `92/95`, UID0000MZ owner/emitter, emitter position `10`, existing `std::vector<RankingCategoryRecord> m_records` formal H, `[[CHILDREN]]` CPP route, and all prior parser/growth/destruction/rollback detail.

### 2026-08-06 B002 UID0003X0 outer-vector growth route

- Reclassified the method-inventory entry as a reviewed false/non-emitting compiler specialization rather than a source helper.
- Added exact parser fast/slow append routes, `0x2b0` growth/deep-copy/nested-lifetime behavior, aligned allocation/free validation, EH rollback, negative reachability, and the `m_records` source-regeneration rule.
- Preserved class `92/95`, owner/emitter UID0000MZ, emitter position `10`, and the exact existing formal CPP/H without adding a helper declaration or body.

### 2026-08-05 B007 UID0003YR outer-vector source implementation

- Raised class metadata from `91/94` to `92/95`, retained owner/emitter UID0000MZ, and set emitter position `10` after the complete record declaration.
- Replaced the raw begin/end/capacity source fields with formal `std::vector<RankingCategoryRecord> m_records`, added `<vector>`, and removed the unsupported explicit destructor declaration.
- Incorporated the exact thunk/teardown caller route, record and nested-vector strides, allocator validation, body hashes, non-emitting child disposition, source accessor forms, header-order requirement, and corrected historical source model without changing parser or reward-response behavior.

### 2026-08-05 B005 UID0003YS compiler-rollback route

- Reclassified the method-inventory entry as a false/blank compiler EH child while retaining this class as semantic owner.
- Added the exact one-caller rollback/free/rethrow sequence, `0x2b0` record stride, `+0x258` nested teardown, zero data/pointer routes, source-container regeneration rule, and rejected ownership/source alternatives.
- Preserved class `91/94`, UID0000MZ owner/emitter, and the existing formal declaration; UID0003YR's independent audit owns any separate outer-vector-destructor change.

### 2026-08-04 B005 UID0002KA selected-record reload callback

- Preserved class metadata, declaration/children emission, reward-response contract, catalog0379 evidence, and all storage-helper boundaries.
- Added reset-before-request ordering, collection-selection preservation, parser-side logical clear/rank reset, row append, optional local metadata, and category-record initial state.
- Distinguished collection `m_selectedCategoryId` from record `m_localPlayerRank` and retained the former selected-user interpretation only as disproved history.

### 2026-07-31 B009 UID0003WU source/header implementation

- Raised class metadata from `87/91` to `91/94` without changing owner/emitter UID0000MZ or reconstructable state.
- Moved the human class declaration from formal CPP to formal H, corrected `GetByIndex(short index)`, and made formal CPP the include-plus-children implementation route.
- Added exact request/response/state behavior and child source relationships while preserving every catalog0379 type/helper fact, parser/helper inventory, storage split, rejected ownership alternative, and historical source-shape correction.

### 2026-07-31 Supervisor catalog0379 post-IDA sync

- Added the minimal incomplete IDA type declaration, exact selected-record helper name/prototype/comment, protected physical readback, and the now-dated catalog0379 backup/post-save identities. Later B7CC current-authority readback preserves those target-specific facts without further mutation.
- Preserved class `87/91`, owner/emitter UID0000MZ, formal `[[CHILDREN]]` declaration, source-level field/method inventory, parser/helper routing, and all historical assumptions.

### 2026-06-23 B001 accepted declaration implementation

- Before: `86/90`, with strong parser/helper evidence but blank class C++.
- Changed to: `87/91`; added declaration-only first-draft C++ with `[[CHILDREN]]`.
- Summary/evidence: current MCP session `80de0a67` reconfirmed constructor behavior, four-field layout, opcode `0x7d` parser/update dispatch, selected-id accessors, and exact child ownership. Parser/helper method bodies stay on exact by-memory children; generated/container support remains blank where already documented.

### 2026-06-17 B002 source-quality execution

- Before: the storage helper link pointed at [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) as one broad helper island.
- Changed to: documented [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) as a non-emitting split/index and added the three collection-owned exact helper children [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md), [UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md), and [UID:0003YU][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md).
- Summary/evidence: B002 rechecked the helper starts, `0x2b0` category-record stride, destructor/growth/copy call paths, owner alternatives, and final-C++ blank policy for generated/container support.

### 2026-06-16 B002 execution-gate support refresh

- Before: `84/88`, with correct broad collection identity but parser names, child split policy, record/user-entry field support, owner route, and the adjacent `0x0045d500-0x0045d528` cleanup funclet still under-documented.
- Changed to: `86/90`, preserving file route through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), and supporting [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) as a direct [UID:0000BK] child.
- Summary/evidence: B002 live IDA read-only checks reconfirmed opcode `0x7d` subcommand dispatch (`1`, `2`, `3`, `6`), exact modeled child ranges, collection offset `RankingDialog + 0x26c`, `0x2b0` record stride, `0x4c` user-entry stride, parser writes to selected/local metadata, user-list paint consumers, and the EH cleanup funclet at `0x0045d500-0x0045d528`. Remaining uncertainty is original source spelling, not ownership, range, or gate-level behavior.

### 2026-05-30 - Grading update

- Before: this class had exact IDA-backed parser/helper coverage but remained unevaluated by the completion/confidence header.
- Changed to: score is now `82/86`, reflecting documented collection construction, packet parsing, selected-category state, accessors, category/user-entry vector growth, deep copy, and storage-helper ownership.
- Summary/evidence: linked memory pages [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) and [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) record IDA-confirmed starts, opcode `0x7d` dispatch, constructor mismatch, and vector helper behavior.

### 2026-05-27 - Added exact IDA-backed memory coverage

- Before: this class pointed only to the broad `RankingDialog` memory page, repeated an unsupported constructor claim that `selectedCategoryId` is initialized to `-1`, and did not list the vector growth/copy helper tail.
- Changed to: linked the exact collection and storage-helper `by-memory` pages, corrected constructor behavior to the three pointer writes shown by IDA, and added the IDA-confirmed helper methods through `0x0045d4f8`.
- Summary/evidence: IDA disassembly of `0x0045c260` shows writes only to `[ecx]`, `[ecx+4]`, and `[ecx+8]`; IDA function inventory confirms the parser/accessor/helper starts from `0x0045c260` through `0x0045d740`; packet handler `0x00459210` calls the parser methods for ranking opcode `0x7d`.

### 2026-06-04 - Parent and live-boundary update

- Before: scored `82/86`, but `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the class unclassified in generated coverage.
- Changed to: scored `84/88`, marked `RECONSTRUCTABLE:TRUE`, and attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
- Summary/evidence: live IDA MCP reverified exact half-open ranges for every listed method/helper, constructor/destructor call sites, opcode `0x7d` parser dispatch, selected-id/count/index accessor bodies, 688-byte category-record stride, and 76-byte user-entry vector growth behavior. Final C++ remains blank because final parser/helper names and source abstraction choices are not 95+.
