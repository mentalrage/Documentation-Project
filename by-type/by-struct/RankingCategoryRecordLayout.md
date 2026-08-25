*** UID:0001VN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000BL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000BL | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingCategoryRecordLayout

## Status

- Confidence: very strong for observed offsets, natural alignment, state width/behavior, the exact standard 32-bit `tm` blocks, by-value accessor ABI, vector behavior, and user-entry fields consumed by `RankingUserListPane`; remaining uncertainty is limited to retail spellings of unrelated tail fields.
- Likely owner: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Primary memory evidence: [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- Size evidence: `688` bytes from category collection stride usage in IDA decompilation and deep-copy helper behavior.
- Reconstructable: source-declared fixed-record layout for the reconstructed ranking dialog module. This type page stays documentation-only; [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) now carries the first-draft declaration so child method definitions have one generated attachment point.
- Score: `93/95`, unchanged. Exact layout, category-list and initial-page parser mapping, partial construction, copy, and lifetime are closed; retail spellings for unrelated tail storage remain the confidence cap.

## UID0003WR Wire Mapping And Default Construction

[UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md) maps each category-list wire record into this physical layout as follows:

| Wire field | Record destination | Exact behavior |
| --- | --- | --- |
| category id BE32 | `+0x04 m_categoryId` | Parsed first and narrowed to source `int`. |
| start date/time BE32 pair | `+0x0c m_startTime` | Date then time passed to the packed start setter; visible fields assigned, unrelated `tm` tail fields untouched. |
| end date/time BE32 pair | `+0x30 m_endTime` | Date then time passed to the packed end setter; visible fields assigned, unrelated `tm` tail fields untouched. |
| state byte | `+0x08 m_stateCode` | Read through signed `char`, then sign-extended into the source `int` field. |
| ANSI title payload | `+0x54 m_title[256]` | CP_ACP conversion with explicit byte length and wide capacity `256`, then copied by the title setter. |
| loop index | `+0x00 m_listIndex` | Signed-short category index. |

The exact inline default-construction baseline is:

- `+0x254 m_totalRankCount = 0`.
- `+0x258/+0x25c/+0x260 m_userEntries` default-constructed empty.
- `+0x264 m_loadedRowsCategoryId = -1`.
- `+0x268 m_localPlayerRank = -1`.
- `+0x2ac m_localPlayerScore = -1`.

The compiler-folded constant at `0x00610bb0` contains twelve zero bytes followed by `ff ff ff ff`, SHA256 `34885EA2EF8490886FAE553C8CE7FFB5A27563825E5F6CE02784875D1ACE0E47`, and is referenced only by category-list and initial-page parsers. It covers the nested-vector triplet plus loaded-row sentinel; separate stores cover total/rank/score.

There is no whole-record zero initialization. Before parser assignment, list index, category id, state, `tm` fields not assigned by the packed setters, title bytes beyond the written terminator, and `+0x26c..+0x2ab m_reservedLocalPlayerFooter` are indeterminate. The reviewed implicit copy copies all fixed spans exactly and deep-copies only the nontrivial vector. The class page owns the inline constructor; this layout page remains blank in formal CPP/H to avoid duplicate emission.

## UID0003WS Initial-Page Wire And Local Baseline

[UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) begins with the same category wire-to-field mapping and exact partial-construction baseline documented above, then conditionally commits page metadata to the selected rebuilt record:

| Initial-page wire value | Record destination | Exact layout behavior |
| --- | --- | --- |
| selected category BE32 | collection `m_selectedCategoryId`; lookup key for record `+0x04` | No record page state is committed unless one rebuilt record matches. |
| signed optional-local flag | control only | Values `1..127` enter the block; zero and negative signed values leave local metadata at its baseline. |
| local rank BE32 | `+0x268 m_localPlayerRank` | Reset first to `-1`, then overwritten only in the present block. |
| local score BE32 | `+0x2ac m_localPlayerScore` | Partial construction supplies `-1`; overwritten only in the present block. |
| local state byte | `+0x08 m_stateCode` | Read as signed `char` and widened through the existing state setter. |
| selected category id | `+0x264 m_loadedRowsCategoryId` | Written only in the present block to identify the loaded local-player metadata. |
| row name/rank/score sequence | `+0x258 std::vector<RankingUserEntry>` | Logical size is cleared without freeing capacity; each `0x4c` row stores category id, rank, `wchar_t name[32]`, and score before ordinary append. |
| final total BE32 | `+0x254 m_totalRankCount` | Stored after all requested rows append; no earlier total commit exists. |

The matched-record pre-page state is therefore precise: row-vector end equals begin, capacity remains unchanged, local rank is `-1`, and the category-list construction baseline still leaves loaded category id and local score at `-1`. With no optional-local block, those three sentinels remain and category-list state at `+0x08` remains unchanged. With a present block, exactly loaded category id, local score, local rank, and state change before row parsing.

Complete store review excludes every byte of `+0x26c..+0x2ab` from UID0003WS. The 64-byte span is copied by implicit record copy but receives no packet value, no local-player name, and no terminator in this parser; `RankingUserListPane` obtains the displayed local name from global `word_69BEE0`. The accepted source consequently preserves `m_reservedLocalPlayerFooter[0x40]` as untouched storage and uses [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)'s narrow collection friendship only for the proved private metadata writes. No new field, tail setter, or layout gap is inferred.

## Layout Hypothesis

`RankingCategoryRecord` stores one ranking event/category plus the ranking rows loaded for that category. It is a plain fixed-size record, not a polymorphic class.

| Offset | Size | Observed field | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | 2 | `listIndex` | `0x0045bf60` returns `*(_WORD*)this`; event-list click logic compares this against the visible row. |
| `+0x02` | 2 | natural compiler alignment, no source member | Standard 32-bit C++ alignment places the following `int categoryId` at `+0x04`; no read, write, copy, or semantic evidence supports an explicit `m_padding02` field. |
| `+0x04` | 4 | `categoryId` | `0x0045bf70` returns `this[1]`; ranking request/reward paths use it as category id. |
| `+0x08` | 4 | `int stateCode` | [UID:0002K2][0x0045bf80-0x0045bf84.RankingCategoryRecordGetStateCode](by-memory/0x0045bf80-0x0045bf84.RankingCategoryRecordGetStateCode.md) returns the full dword; the raw setter accepts a four-byte argument; parsers widen a packet byte into this slot. State `0` enables the action/selects the first glyph, state `1` is the post-claim/second-glyph state, and state `2` disables the action and suppresses the glyph. |
| `+0x0c` | 36 | `tm m_startTime` | [UID:0002K3][0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts](by-memory/0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md) returns the complete nine-int value by value; [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md) writes the first six `tm_*` fields and leaves the final three untouched. |
| `+0x30` | 36 | `tm m_endTime` | [UID:0002K4][0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts](by-memory/0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md) returns the symmetric complete value; [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) writes the first six fields and leaves the final three untouched. |
| `+0x54` | 512 | `wchar_t title[256]` | `0x0045bfd0` returns `+0x54`; parser converts bounded title text into this buffer; next named field is `+0x254`. |
| `+0x254` | 4 | `totalRankCount` / `totalUserCount` | Subcommand `2` and `3` parsers store final total count; user-list paint formats `"Total : %d"`. |
| `+0x258` | 4 | physical user-entry vector begin | `GetUserEntryAt`, reset, append, clone, and cleanup helpers use this first slot of source member `std::vector<RankingUserEntry> m_userEntries`. |
| `+0x25c` | 4 | physical user-entry vector current/end | Bounds checks and [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md) use this second slot; the source-level reset is `m_userEntries.clear()` and preserves capacity. |
| `+0x260` | 4 | physical user-entry vector capacity | Append/growth helpers compare the current-end pointer against this third slot of the same source `std::vector`. |
| `+0x264` | 4 | `loadedRowsCategoryId` / `currentRowsCategoryId` | Row parsers store the active category id when row metadata is loaded. |
| `+0x268` | 4 | `m_localPlayerRank` | [UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md) writes the unavailable sentinel `-1`; row parsers optionally update it; user-list paint displays the local-player footer only when positive. |
| `+0x26c` | 64 | copied/reserved local-player footer tail (`m_reservedLocalPlayerFooter[0x40]`) | Deep-copy preserves this tail between `localPlayerRank` and `localPlayerScore`, and its size matches a possible wide-name buffer; however, checked row parsers do not write it and `RankingUserListPane::OnPaint` reads the displayed footer name from global `word_69BEE0` through `0x005a2dc0`, not from this record field. |
| `+0x2ac` | 4 | `localPlayerScore` / `localPlayerValue` | User-list paint formats this value in the local-player footer. |

## UID0003WT Ranking-Row Wire-To-Field Contract

[UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) gives an exact independent subcommand-2 write map for a pre-existing selected record:

| Packet field / operation | Record destination / effect |
| --- | --- |
| BE32 category id at `packet + 2` | Compared first with collection selection and then with `m_categoryId` at `+0x04`; mismatch/no record returns before mutation. |
| Found-record reset | Logical `m_userEntries.clear()` (`+0x25c = +0x258`) without capacity release, then `m_localPlayerRank` at `+0x268` becomes `-1`. |
| Signed optional-local flag at `packet + 6` | Only signed-positive values enter the metadata block. |
| BE32 local rank at `packet + 7` | `m_localPlayerRank` at `+0x268`. |
| BE32 local score at `packet + 11` | `m_localPlayerScore` at `+0x2ac`. |
| Response category id | `m_loadedRowsCategoryId` at `+0x264`. |
| Signed state byte at `packet + 15` | `m_stateCode` at `+0x08` through the source-facing setter. |
| UInt16BE row count at current cursor | Narrowed to signed `short`; negative values skip row append. |
| Per-row category/rank/name/score | One exact `0x4c` `RankingUserEntry` appended to `m_userEntries`. |
| Final BE32 total after all rows | `m_totalRankCount` at `+0x254`, committed last. |

The optional block has no store to `+0x26c..+0x2ab`. Those 64 bytes remain copied/reserved footer storage, not a packet-populated local-player name. When the optional flag is absent, only the unconditional row clear and rank `-1` baseline occur; prior `m_loadedRowsCategoryId`, `m_stateCode`, reserved tail, and `m_localPlayerScore` survive. This exact asymmetric state rejects whole-object clearing and copied assumptions from older footer interpretations.

Each wire row consumes an unsigned-byte ANSI name length, converts through `CP_ACP` into a 256-WCHAR temporary, and copies exactly into the 32-WCHAR row field. The stack object assignment order is category id, score sentinel `-1`, rank, secure name copy, final score, then append. Row count and cursor remain signed `short`, and the parser supplies no packet-length, conversion-result, count, or rollback checks; completed mutations survive a later failure.

## UID0003X4 Binary Copy-Span Proof

[UID:0003X4][0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep](by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md) independently validates the complete 688-byte layout through one compiler-generated implicit copy-constructor lowering:

| Copy span | Exact interpretation |
| --- | --- |
| `+0x000..+0x00b` | Copies list index, natural alignment, category id, and four-byte state. The copied `+0x02..+0x03` bytes prove physical alignment continuity, not a source-authored padding member. |
| `+0x00c..+0x02f` | Copies all 36 bytes of `tm m_startTime` verbatim. |
| `+0x030..+0x053` | Copies all 36 bytes of `tm m_endTime` verbatim. |
| `+0x054..+0x253` | Copies exactly 512 title bytes; compiler `rep movsd` count `0x80` matches `wchar_t m_title[256]`. |
| `+0x254..+0x257` | Copies total rank/user count. |
| `+0x258..+0x263` | Does not shallow-copy three pointers. It invokes [UID:0003X3][0x0045d370-0x0045d419.RankingUserEntryVectorClone](by-memory/0x0045d370-0x0045d419.RankingUserEntryVectorClone.md) to initialize and deep-copy the sole nontrivial member `std::vector<RankingUserEntry> m_userEntries`. |
| `+0x264..+0x26b` | Copies loaded-rows category id and local-player rank. |
| `+0x26c..+0x2ab` | Copies the exact 64-byte reserved/footer tail while leaving its original private spelling unresolved. |
| `+0x2ac..+0x2af` | Copies local-player score and completes the exact `0x2b0` record. |

The body is 216 bytes, 57 instructions, one block, SHA256 `02E0572F07330D31B77690BD8BD7902EA80D564CB2A5B9305A0B1B57C51527E3`. Its five call sites are ordinary parser append, outer-vector growth, and range-copy uses. Zero data/pointer routes and the absence of custom behavior support an implicit special member rather than an authored helper. This layout page therefore remains blank in formal CPP/H; UID0000BL's existing natural C++ declaration is the source authority.

## Reward-Claim Status Response Evidence

[UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md) provides a direct paired read/write use of the first two semantic dwords. The response handler reads the packet category id, scans collection records, compares each record's `+0x04` dword as `categoryId`, and writes the claimed state value `1` to that same record's `+0x08` dword. In human source terms these operations are the inlined equivalents of `GetCategoryId()` and `SetStateCode(1)`.

This evidence reinforces the existing four-byte widths and field order without changing the owner/emitter route. The accepted `tm`/accessor resolution raises this page to `92/95`; the reward-status evidence also rejects byte-sized state storage because the handler performs a full dword write at `+0x08`, while the one-byte packet status only controls whether the collection scan and state transition occur.

## Nested User Entry

[UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md) proves a user-entry stride of `76` bytes. Its exact body is `[0x0045bfe0,0x0045c01b)`, followed by one existing unnamed, untyped, non-code data item at `[0x0045c01b,0x0045c020)`, size `5`, containing `cc cc cc cc cc`, with blank comments and zero xrefs. That item is compiler/alignment evidence only: it is not a source member, child, or emitted body. The row layout is consumed by [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md), and parser/append/paint evidence now supports the current `categoryId`, `rank`, `name`, and `score` field names as high-probability source-facing names.

The accessor subtracts physical end from begin, divides by `0x4c`, and compares that signed count only against the upper bound. It returns null when `count <= index`; otherwise it forms `begin + 0x4c * index`. No lower-bound check exists, so a negative index takes the success path and forms a pointer before begin even though the sole release caller supplies only `0..9`. The source-facing decision is therefore a non-const mutable `RankingUserEntry *GetUserEntryAt(int index)` over `std::vector<RankingUserEntry> m_userEntries`, without `index >= 0`, `at()`, exception handling, raw pointer members, or `const_cast`.

`0x0045c1e0` appends one 76-byte row to the vector at `+0x258`. If current end equals capacity it calls growth helper `0x0045d1b0`; otherwise it copies 76 bytes into the current end and advances `+0x25c` by `0x4c`.

2026-06-16 C001 and B002 cross-checks against [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md) and the collection row parsers narrow the user-entry row fields that are currently safe:

| Row offset | Size | Observed field | Evidence |
| --- | ---: | --- | --- |
| `+0x00` | 4 | `categoryId` | Row parser stores the parent/loaded category id into each row before append. |
| `+0x04` | 4 | `rank` | `RankingUserListPane::OnPaint` formats this rank column. |
| `+0x08` | 64 | `wchar_t name[32]` | Row parser converts player name text here; paint uses this as the name column. |
| `+0x48` | 4 | `score` | Row parser stores the per-row score/value dword; `score` is preferred for ranking UI semantics because paint formats it as the score column. |

Any subfields inside the name buffer remain unnamed. The current pass checked the append helper, parser stores, and paint consumer; exact original source spelling of `score` remains below final-C++ quality, but `score` is the strongest current descriptive field name.

### Reset And Lifetime Invariants

The exact UID0002KA body is `[0x0045c240,0x0045c257)`, 23 bytes:

~~~asm
mov eax, [ecx+258h]
mov [ecx+25Ch], eax
mov dword ptr [ecx+268h], 0FFFFFFFFh
retn
~~~

This lowering proves:

- `m_userEntries.clear()` sets physical end `+0x25c` to begin `+0x258` without changing begin or capacity `+0x260`.
- The trivial `0x4c`-byte `RankingUserEntry` layout requires no per-element destructor loop.
- [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md) is the separate lifetime operation that frees storage and zeros all three pointers.
- Category-list construction starts with a null triplet, local rank `-1`, local score `-1`, and total count zero. The initial-page and ranking-row parsers inline end=begin and rank=`-1` before loading replacement data.
- The sole reset caller at `0x004594f7` immediately overwrites `EAX`, so the source method is `void`.

Historical raw-field source and selected-user-index interpretations are retained only as compiler-layout history. The class declaration correctly exposes one `std::vector<RankingUserEntry> m_userEntries` and `int m_localPlayerRank`.

## Date/Time Part Blocks

Both 36-byte date/time blocks are exact standard 32-bit `tm` values. Live IDA already defines `tm` as nine ordered four-byte `int` members, matching every copied dword and every setter/paint offset without an invented support type.

[UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md) has half-open range `0x0045c050-0x0045c0f9`, raw offset `0x5b450`, length `0xa9`, SHA1 `6f8ad81d88a47803ddb555472dcad2896cfa0ce5`, full return bytes `c2 08 00`, and seven-byte `0xcc` padding at `0x0045c0f9-0x0045c100`. It writes `tm_year/tm_mon/tm_mday` first from `packedDate`, then `tm_hour/tm_min/tm_sec` from `packedTime`; the offset-sorted table lists the time fields first.

[UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) has half-open range `0x0045c100-0x0045c1a9`, raw offset `0x5b500`, length `0xa9`, SHA1 `5db36d68b861e1df28309949538868a3f61c2d40`, full return bytes `c2 08 00`, and seven-byte `0xcc` padding at `0x0045c1a9-0x0045c1b0`. It writes the same first six fields in `m_endTime` and does not write `tm_wday`, `tm_yday`, or `tm_isdst` at record offsets `+0x48/+0x4c/+0x50`.

| Relative `tm` offset | Field | Record start offset | Record end offset | Writer/consumer behavior |
| --- | --- | --- | --- | --- |
| `+0x00` | `int tm_sec` | `+0x0c` | `+0x30` | Setter writes `packedTime % 100`; paint prints seconds. |
| `+0x04` | `int tm_min` | `+0x10` | `+0x34` | Setter writes `(packedTime % 10000) / 100`; paint prints minutes. |
| `+0x08` | `int tm_hour` | `+0x14` | `+0x38` | Setter writes `packedTime / 10000`; paint prints hours. |
| `+0x0c` | `int tm_mday` | `+0x18` | `+0x3c` | Setter writes `packedDate % 100`; paint prints day. |
| `+0x10` | `int tm_mon` | `+0x1c` | `+0x40` | Setter stores direct packet month; paint prints it without normalization. |
| `+0x14` | `int tm_year` | `+0x20` | `+0x44` | Setter stores direct full year; paint prints it without subtracting/adding 1900. |
| `+0x18` | `int tm_wday` | `+0x24` | `+0x48` | Copied by getter; checked setters/parsers leave untouched; paint does not read. |
| `+0x1c` | `int tm_yday` | `+0x28` | `+0x4c` | Copied by getter; checked setters/parsers leave untouched; paint does not read. |
| `+0x20` | `int tm_isdst` | `+0x2c` | `+0x50` | Copied by getter; checked setters/parsers leave untouched; paint does not read. |

Rejected layout alternatives:

- Do not model these blocks as `SYSTEMTIME`: its widths/order and total size do not match.
- Do not shrink the value to six dwords: both accessors copy `0x24` / 36 bytes, so all nine `tm` integers are part of the binary contract.
- Do not normalize `tm_mon`/`tm_year` or initialize the final fields. The client uses standard `tm` storage non-conventionally by keeping direct protocol values; that runtime behavior does not disprove the exact type identity.
- The historical custom `RankingDateTimeParts` hypothesis and its rejection of `tm` are superseded, not erased. That earlier model correctly established the first-six order and 36-byte copy, but misidentified the last three known `tm` fields as reserved.

Observed packed-date setter writes:

| Block | Offset | Stored value |
| --- | --- | --- |
| start | `+0x0c` | `packedTime % 100` |
| start | `+0x10` | `(packedTime % 10000) / 100` |
| start | `+0x14` | `packedTime / 10000` |
| start | `+0x18` | `packedDate % 100` |
| start | `+0x1c` | `(packedDate % 10000) / 100` |
| start | `+0x20` | `packedDate / 10000` |
| end | `+0x30` | `packedTime % 100` |
| end | `+0x34` | `(packedTime % 10000) / 100` |
| end | `+0x38` | `packedTime / 10000` |
| end | `+0x3c` | `packedDate % 100` |
| end | `+0x40` | `(packedDate % 10000) / 100` |
| end | `+0x44` | `packedDate / 10000` |

## Storage Helper Split

B002's 2026-06-17 source-quality pass split the former [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) broad page into exact child helpers. [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md) and [UID:0003YV][0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage](by-memory/0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage.md) confirm the record-owned `RankingUserEntry` vector semantics at `+0x258/+0x25c/+0x260`; the category-record range helpers attach to [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md).

### UID0003YR Outer Category Vector Destruction Cross-Reference

[UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md) is the compiler-generated teardown for [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)'s source member `std::vector<RankingCategoryRecord> m_records`. It does not change this record's exact size or field layout. The outer loop advances at exact record stride `0x2b0`, and for each element it passes `record + 0x258` to UID0003YT before releasing outer storage. That receiver proves the nested member starts at the established `m_userEntries` offset and that every outer record destruction includes the nested vector lifetime.

After the record walk, UID0003YR applies the MSVC small/large allocation free split to the collection's outer capacity span, validates recovered large-allocation metadata, frees the allocation, and clears the outer begin/end/capacity triplet. Exact target body SHA256 is `BD68BC2529D22C1E3F240894411081A291B663A38B45EC1B1130BB149034C24D`. Its only incoming route is the five-byte collection destructor thunk, body SHA256 `BF61252F1E61B859B1994B42177DBE6C9E3859519FCFEA28A27E51A8FC5F11D4`.

This is cross-container lifetime evidence, not a field or emitted body for the record layout. The source declarations remain `std::vector<RankingCategoryRecord> m_records` on UID0000BK and `std::vector<RankingUserEntry> m_userEntries` at `+0x258` on UID0000BL. UID0003YR is non-reconstructable/non-emitting with blank formal CPP/H; this layout page also remains blank because the class page owns the record declaration.

### UID0003YT Physical Teardown Model

The three physical dwords at `+0x258`, `+0x25c`, and `+0x260` are the begin, end, and capacity slots of source member `std::vector<RankingUserEntry> m_userEntries`; they are not three developer-authored pointer fields. [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md) receives the triplet address. A null begin returns. For non-null storage, `(capacity - begin)` is divided by the exact `0x4c` row stride through compiler strength reduction, then multiplied back to recover the capacity allocation span.

Spans below `0x1000` free begin directly. Larger spans recover the raw allocation from `begin[-1]`, add `0x23` to the size, and require `(begin - raw - 4) <= 0x1f`; failure calls exact runtime symbol `__invalid_parameter_noinfo_noreturn`. Success calls free wrapper `sub_5C7526` and writes zero to begin, end, and capacity in order. There is no per-row destructor loop because the 76-byte `RankingUserEntry` layout is trivial: two leading integers, inline `wchar_t name[32]`, and a trailing score integer.

The exact 99-byte specialization is reached from nine lifetime/EH sites, including collection teardown, range teardown, parser replacement, vector growth, and compiler unwind. The `0x45bf56` call belongs to an existing `[0x0045bf50,0x0045bf5b)` tail chunk owned by `sub_45C2A0`; the old ownerless interpretation is rejected history. UID0003YT must remain non-emitting with blank formal CPP/H. The class member declaration must regenerate equivalent container support while preserving the observed stride, capacity-based allocation size, large-allocation header check, free, and triplet poststate.

The three physical pointers are compiler-layout evidence, not three independent developer-facing fields. Append, growth, bounds checks, reset, clone, destruction, and allocation all match one 32-bit `std::vector<RankingUserEntry>`. [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) therefore declares `std::vector<RankingUserEntry> m_userEntries` while this page preserves the exact begin/end/capacity offsets needed for binary-layout verification.

## Evidence Notes

- 2026-05-31 IDA MCP recheck confirmed all eleven method starts, current decompilation of the date/time setters, the 76-byte user-entry copy in `AppendUserEntry`, caller sets for every accessor/helper, and `688`-byte category-record stride in collection parser loops.
- 2026-08-04 B007 read-only MCP session `9081c1f3-bc94-49a3-a909-a60eafeb0a99` reconfirmed UID0002K6 size `0x3b`, body SHA256 `775ce790509e5e305dd258b915880e77e78219e06e4679c6c9b607e988277372`, sole call at `0x0045f637`, no callees, exact signed comparison, `0x4c` pointer arithmetic, terminal `c2 04 00`, and the five-byte `0xcc` postpad. The current IDB has no original target/type symbols, so the selected method/member/row spellings remain evidence-backed source reconstruction rather than recovered lexical proof.
- Fresh Gate2B prestate on 2026-08-04 corrected the physical postpad model: `inspect_items` at `0x0045c01b..0x0045c01f` returns one shared item with head `0x0045c01b`, end `0x0045c020`, size `5`, unnamed, untyped, `is_code:false`, `is_data:true`, bytes `cc cc cc cc cc`, blank comments, and zero xrefs. The layout/source conclusions are unchanged because this item emits no source and lies after the method body.
- 2026-06-16 C001 live IDA refresh reconfirmed all eleven starts/sizes and xrefs, including nine `GetCategoryId` xrefs, start/end copy callers from `RankingUserListPane::OnPaint`, setter callers from category parse/load routines, `AppendUserEntry` from the ranking-row parser, and `ResetUserEntries` from category-selection/update flow.
- C001 applied and saved IDA names for all eleven `RankingCategoryRecord_*` helper/accessor methods.
- IDA caller evidence confirms the disabled helpers are used by ranking event-list drawing, user-list painting, reward-info drawing, and selected-category reset paths.
- 2026-06-19 B015 K7 raw PE recheck confirms direct parser callsites at `0x0045c49c` and `0x0045c770`, no callees, no VA/RVA/raw pointer route, and compiler-lowered division constants `0x68db8bad` and `0x51eb851f` for `/10000` and `/100`.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md)
- [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md)
- [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md)
- [UID:0003YV][0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage](by-memory/0x0045d6e0-0x0045d740.RankingUserEntryVectorAllocateStorage.md)

## Changes

### 2026-08-14 B003 UID0003WT row-response layout callback

- Preserved `93/95`, UID0000BL owner/emitter routing, blank formal channels, exact `0x2b0` record and `0x4c` row layouts, and all B001 UID0003WS work.
- Added the exact subcommand-2 packet-to-field map, reset/present/absent metadata states, signed count/cursor and flag rules, row construction order, no-reserved-tail-write proof, final-total ordering, and partial-success behavior.

- 2026-08-14 B001 UID0003WS initial-page layout callback:
  - Preserved `93/95`, UID0000BL owner/emitter routing, blank formal channels, exact `0x2b0` layout, and all prior wire/copy/lifetime evidence.
  - Added the complete selected-record wire map, reset and absent-local baselines, exact four-field present-local writes, row/total commit order, and complete no-reserved-footer result.
  - Linked the private stores to the narrow class friendship without inventing a tail field, public setter, or second emitted declaration.

- 2026-08-14 B005 UID0003WR layout callback:
  - Raised completion from `92` to `93` while retaining confidence `95`, owner/emitter UID0000BL, and documentation-only blank formal channels.
  - Added the exact category-list wire-to-field map, signed state/index behavior, partial constructor sentinel/vector baseline, shared constant bytes/hash/two-parser proof, and intentionally uninitialized spans.

- 2026-08-06 B007 UID0003X4 copy-span callback:
  - Added exact fixed and nontrivial copy spans across all `0x2b0` bytes, the 512-byte title bulk-copy proof, sole `+0x258` nested-vector deep-copy distinction, and the natural-alignment/no-authored-padding conclusion.
  - Preserved `92/95`, UID0000BL ownership/emission, the existing offset table, and blank formal channels because the class page owns the developer-facing declaration.

- 2026-08-05 B007 UID0003YR outer-lifetime callback:
  - Preserved `92/95`, UID0000BL owner/emitter routing, the exact 688-byte record layout, and blank formal CPP/H.
  - Added the outer `std::vector<RankingCategoryRecord>` teardown route, `0x2b0` record walk, `+0x258` nested-member receiver, exact body hashes, outer allocator validation, source-regeneration boundary, and explicit no-layout/no-emission conclusion.

- 2026-08-04 B007 UID0003YT layout callback:
  - Preserved `92/95`, UID0000BL owner/emitter routing, the 688-byte record, and blank layout CPP/H.
  - Added the exact physical triplet, `0x4c` capacity arithmetic, small/large allocation split, aligned-header validation, double-underscore invalid-parameter route, free/triplet clearing, trivial-row no-loop conclusion, nine-call lifetime context, and compiler-regeneration boundary.

- 2026-08-04 B005 UID0002KA layout-support implementation:
  - Preserved metadata at `92/95`, UID0000BL owner/emitter routing, and blank formal channels because the class page owns the declaration.
  - Added exact clear-without-free lowering, capacity/destructor distinction, parser initialization, `m_localPlayerRank` sentinel/paint behavior, sole-caller `void` proof, and the historical raw-field/selected-user correction.
- 2026-08-04 B007 C29 Gate2B-prestate correction:
  - Added the exact existing postpad data-item model to the UID0002K6 nested-entry evidence and distinguished it from the 688-byte source-authored record layout, child coverage, and emitted code.
  - The earlier five-byte alignment conclusion remains valid; only the unstated/incorrect physical-item representation is corrected. Metadata, owner/emitter routing, formal blocks, and all unrelated layout evidence remain unchanged.

- 2026-08-04 B007 UID0002K6 layout-support callback:
  - Preserved metadata at `92/95`, owner/emitter UID0000BL, blank formal CPP/H, the exact 688-byte record model, and every unrelated `tm`, footer, and storage-helper conclusion.
  - Added the corrected `0x0045c01b` endpoint and postpad, exact signed upper-bound-only count semantics, negative-index before-begin result, mutable non-const vector accessor decision, sole `0..9` paint caller, and live body/hash evidence.
  - Retained the physical `+0x258/+0x25c/+0x260` triplet as compiler-layout evidence while rejecting it as three developer-authored source members.

- 2026-08-02 B009 UID0002K3 standard-`tm` layout callback:
  - Raised the layout from `87/91` to `92/95`, preserving owner/emitter UID0000BL and blank formal CPP/H because the class page owns the source declaration.
  - Replaced the current custom-block hypothesis with exact standard 36-byte `tm` members at `+0x0c` and `+0x30`, including all nine integer fields, by-value getter copies, first-six-field packed setter writes, untouched `tm_wday/tm_yday/tm_isdst`, and direct month/full-year protocol semantics.
  - Retained earlier `RankingDateTimeParts` and reserved-dword conclusions only as historical assumptions that established byte order before the live UDT/ABI/consumer evidence resolved the source-facing type.

- 2026-07-31 B009 UID0003WU ordinary implementation callback:
  - Preserved metadata at `87/91`, owner/emitter UID0000BL, and blank formal CPP/H.
  - Added the reward-claim response handler's direct `+0x04` category-id comparison and full-dword `+0x08 = 1` state transition, tying the physical layout to the source-facing `GetCategoryId()` and `SetStateCode(1)` operations.
- 2026-07-30 B007 UID0002K2 ordinary implementation callback:
  - Preserved metadata at `87/91` with owner/emitter UID0000BL.
  - Added exact natural alignment at `+0x02..+0x03`, the four-byte `int` state field and complete `0/1/2` behavior at `+0x08`, and the distinction between physical vector slots and source-facing `std::vector<RankingUserEntry> m_userEntries`.
- 2026-06-20 B001 accepted K8 implementation:
  - Updated end-time setter support to the corrected [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) range `0x0045c100-0x0045c1a9`.
  - Added raw byte/padding evidence, direct parser callers `0x0045c4b3` and `0x0045c787`, no-callee/no-pointer-route evidence, and clarified that the setter initializes the six visible end `RankingDateTimeParts` fields while preserving the reserved dwords.
  - Corrected packed-setter write-order prose: the raw code stores date fields first and then time fields; offset-sorted tables still list time fields first because of the `RankingDateTimeParts` layout.
- 2026-06-19 B015 accepted K7 implementation:
  - Updated start-time setter support to the corrected [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md) range `0x0045c050-0x0045c0f9`.
  - Added raw byte/padding evidence and clarified that the setter initializes the six visible start `RankingDateTimeParts` fields while preserving the reserved dwords.
  - Paired [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) now has the symmetric endpoint/source-quality implementation.
- 2026-06-18 B005 RankingUserListPane source-quality correction:
  - Before: the `+0x26c` tail was documented as proved `wchar_t localPlayerName[32]` storage.
  - Changed to: copied/reserved local-player footer tail storage, preserving the observed 64-byte copied field while removing the unsupported consumed-name claim.
  - Evidence: B005 rechecked parser writes, deep-copy behavior, and `RankingUserListPane::OnPaint`; the footer rank/score are record fields, but the displayed name is built from global `word_69BEE0` through `0x005a2dc0`.
- 2026-06-17 B002 source-quality execution:
  - Refined the date/time blocks to `RankingDateTimeParts`, documenting the validated second/minute/hour/day/month/year order plus three reserved copied dwords.
  - Added the [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md) storage-helper split note and links to the exact user-entry vector helper children that support the `+0x258/+0x25c/+0x260` vector member. Formal C++ remains blank on this type page because the class page now emits the draft declaration.
- 2026-06-16 B002 RankingCategoryCollection support refresh:
  - Before: `85/90`, with a correct record stride and vector/date method evidence but stale `+0x54` title size and unresolved user/local metadata.
  - Changed to: `87/91`, preserving owner/emitter route through [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md).
  - Evidence: collection parser review, row append/deep-copy helpers, and user-list paint consumers resolved title length, total count, row category id, local-player rank/score, and user-row fields. B005 later corrected the local-player name claim: the `+0x26c` tail is copied/reserved footer storage, while the displayed footer name comes from global `word_69BEE0`. Remaining uncertainty is exact original source type spelling for date/time blocks and score/value naming, not offset identity.
- 2026-06-16 B002 AppendUserEntry source-quality refresh:
  - Metadata unchanged at `87/91`.
  - Evidence: [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md) and [UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) rechecked the stack row construction and append copy, strengthening `RankingUserEntry` as `{ categoryId, rank, wchar_t name[32], score }` with size `0x4c`. The exact original spelling of `score` remains below final-C++ quality, but the row layout no longer blocks method scoring or ownership.

- 2026-06-05: Raised from `78/86` to `82/88` after live IDA reconfirmed all method starts, start/end packed-date writes, title and user-entry vector offsets, append/growth use of `+0x258/+0x25c/+0x260`, and the deep-copy helper's 688-byte record copy. Removed recovered-output caveats and kept final declaration blank.
- 2026-06-16 C001 type-layout refresh:
  - Before: `82/88`, with the core record offsets documented but direct class/memory support still at `84/88`, no current IDA names, and user-entry row fields still too broad.
  - After: `85/90`, preserving owner/emitter route through [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) and final C++ blank.
  - Evidence: live IDA reconfirmed method sizes/xrefs, exact accessor and copy offsets, setter writes into start/end date-time blocks, vector begin/current/capacity offsets, 76-byte append stride, reset of `+0x268`, and `RankingUserListPane` reads at row `+0x04/+0x08/+0x48`. C001 saved eleven method names in IDA. Remaining blockers are final date/time part type names, the row prefix, `+0x264`, and the `+0x26c` tail.
- 2026-05-31: Grading changed from `0/0` to `78/86`, marked reconstructable, and attached to [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md).
  - Before: page contained a useful offset table but still looked unevaluated to validator/stat tooling.
  - After: score reflects current IDA-verified method starts, caller evidence, date/time setter writes, vector offsets, record stride, and known remaining caveats for final field names and tail storage.
  - Evidence: IDA MCP `lookup_funcs`, `decompile`, and `callers` checks on 2026-05-31 for the eleven exact method starts and collection/parser callers.
- 2026-05-27: Expanded the date/time blocks and user-entry vector evidence after IDA confirmed `0x0045c050`, `0x0045c100`, and `0x0045c1e0`. Before this change, the layout only documented copy/access/reset helpers and did not capture the packed-date setters or append behavior.
