*** UID:0000MZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# RankingDialog

## Status

- Confidence: very strong for ranking UI source grouping, child ownership, vtable/singleton evidence, packet-family evidence, accepted helper/setter child splits, explicit pollution exclusions, and UID0004YX's resolved inherited lookup/enabled-state APIs; medium-high only for exact original filename versus compact feature split and broader unresolved helpers/layout.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/RankingDialog.cpp`
- Evidence basis: IDA MCP function listing, decompilation, byte checks, vtable references, packet/resource use, exact child memory pages, accepted UID0003WS initial-page parser behavior/source/access evidence, accepted UID0004ZM retained-body/inlined-call evidence from session `b3b2bf88`, 2026-06-16 live A002 support refreshes, and 2026-06-29/30 B006 narrowed empty-emitter callback evidence from active database `supervisor_resume_20260629`. Recovered one-class container names are treated only as search aids when they are mentioned.

## UID0003WR Category-List Parser Source Contract - 2026-08-14

- [UID:0003WR][0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse](by-memory/0x0045c2a0-0x0045c556.RankingCategoryCollectionParseCategoryListResponse.md) now emits the exact opcode `0x7d` subcommand `1` method through [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) into `NexusTK/ui/dialogs/RankingDialog.cpp`; the existing class declaration supplies the one `RankingDialog.h` method declaration, so the child H block remains blank.
- The parser clears `m_records`, narrows the UInt16BE category count and packet cursor to signed `short`, reads each 22-byte fixed category header plus unsigned-byte title payload, preserves signed-char state, converts text through CP_ACP with explicit length/capacity, and applies the existing record setters before ordinary `push_back`.
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) now supplies the exact inline partial default constructor in `RankingDialog.h`: empty user-entry vector, total count `0`, and loaded-category/rank/score sentinels `-1`. Parser-overwritten fields and unrelated `tm`/title/reserved tails are intentionally not whole-zeroed; the implicit deep copy remains compiler-generated.
- Failure after entry leaves the collection empty or with the successfully appended prefix. UID0003X4 deep copy, UID0003X0 growth, nested-vector destruction, external EH chunks, range-check, and cookie support remain non-emitting consequences of ordinary source.
- The shared readers are declared by [UID:0003YK][0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers](by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md) in `NexusTK/network/PacketBuffer.h`; no Ranking-local helper declaration or body is valid. UID0000BK's repaired CPP preamble supplies `<windows.h>`, `MemoryMan.h`, `RankingDialog.h`, and `PacketBuffer.h` before child definitions. The earlier direct-CRT `<string.h>` route is superseded history.
- The unique source route remains `ui/dialogs/RankingDialog.cpp/.h`, not a new collection file or PacketBuffer-owned feature parser. File score remains `88/91` because this exact child is closed while broader private helpers/file split and other generated cleanup remain independent caps.

## UID0003WS Initial Category/Page Source Contract - 2026-08-14

- [UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) owns the complete source definition for opcode `0x7d` subcommand `3`. It emits through [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) into `NexusTK/ui/dialogs/RankingDialog.cpp`; UID0000BK's existing formal H owns the sole method declaration in `NexusTK/ui/dialogs/RankingDialog.h`, so the child formal H remains blank.
- Entry clears the category vector, uses a signed-short UInt16BE category count and signed-short cursor from offset `4`, parses BE32 category/date/time fields plus signed state and unsigned title length/text, converts through `MemoryMan::MemmoveWrapper` and `MultiByteToWideChar(CP_ACP, ..., 256)`, applies record setters, and ordinary-appends partially constructed records.
- Selection is committed only when the selected id matches one of the rebuilt records. A miss returns with the rebuilt list or successful prefix intact and leaves prior selection/page state uncommitted. A match clears the record's row-vector logical size without releasing capacity and resets local rank to `-1`.
- The signed optional-local flag executes only for `1..127`; it writes exactly loaded category id, local score, local rank, and state. It never writes the 64-byte reserved/copied footer tail. An absent block preserves loaded category id/rank/score sentinels `-1`, category-list state, and the untouched tail.
- Signed-short row count controls exact `0x4c` user-row appends after CP_ACP name conversion, and final BE32 total is stored last. Negative row count skips appends and reads total at the current cursor. There are no packet bounds/count/conversion/rollback guards; successful destructive work and appended prefixes remain visible when later operations fail.
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) owns the exact narrow `friend class RankingCategoryCollection;` declaration in formal H. It makes the proved private metadata writes legal without adding setters or broadening field visibility. UID0000BL emits at header position `0`, before UID0000BK at position `10`, so the record declaration and friendship precede the collection's `std::vector<RankingCategoryRecord>` member and method declaration.
- Shared BE16/BE32 readers remain PacketBuffer-owned; MemoryMan/Win32 dependencies remain in the collection CPP preamble. Ordinary vector append, deep copy, growth, destruction, EH cleanup, security-cookie, and range-check lowerings remain generated rather than separate source functions.
- The expected coherent generated result is exactly one UID0003WS method definition in `RankingDialog.cpp`, one existing declaration in `RankingDialog.h`, one record-to-collection friend declaration in `RankingDialog.h`, record-before-collection header order, no duplicate definition/declaration/friend, and no UID0003WS empty-emitter marker. File score remains `88/91`; this child is closed without changing unrelated module-level caps.

## UID0003WT Selected Ranking Rows Source Contract - 2026-08-14

- [UID:0003WT][0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse](by-memory/0x0045cb10-0x0045cdb4.RankingCategoryCollectionParseRankingRowsResponse.md) owns the complete opcode `0x7d` subcommand `2` definition. It emits through [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) into `NexusTK/ui/dialogs/RankingDialog.cpp`; UID0000BK's existing formal H owns the sole declaration in `RankingDialog.h`, so the child H channel remains blank.
- The dispatcher has one call at `0x004592ca`. The paired `RequestRankingPage` sends selected category id and one-based inclusive bounds `10 * page + 1` through `10 * (page + 1)`.
- The parser returns before mutation when the response category id differs from collection selection or when no matching `0x2b0` record exists. A found record is cleared without releasing row capacity and receives an explicit local-rank `-1` baseline.
- A signed-positive optional flag writes exact local rank, local score, loaded category id, and state in observed order. It does not write the reserved/copied `+0x26c..+0x2ab` footer tail. When absent, loaded id, state, tail, and score remain unchanged while rank remains `-1`.
- Row count and cursor are signed `short`. Each unsigned-byte-length ANSI name is copied through MemoryMan, explicitly terminated, converted with `MultiByteToWideChar(CP_ACP, ..., 256)`, explicitly wide-terminated, and securely copied into an exact `0x4c` category/rank/32-WCHAR-name/score row before ordinary append. Final BE32 total commits last.
- There are no null, packet-length, count, name-length, conversion-result, bounds, or method-level rollback guards. Reset and completed appends remain visible if a later conversion, secure copy, allocation, or range-check path fails.
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) already owns the exact narrow `friend class RankingCategoryCollection;` in formal H, before `public:`. This is the legal route for proved private metadata writes; no public setters or duplicate declaration are introduced.
- The body is exactly `[0x0045cb10,0x0045cdb4)`, SHA256 `B1C3573A44D5F534DB1A68FDBFED5612219556051A811DA63AE0F359DC265677`. Six-byte predecessor and twelve-byte successor `CC` pads remain separate non-emitting data. PacketBuffer readers, MemoryMan, Win32 conversion, secure copy, record methods, and ordinary vectors are dependencies; range-check, cookie, vector growth/copy, and EH support remain compiler-generated.
- The coherent generated result must contain exactly one complete UID0003WT method definition in `RankingDialog.cpp`, the existing declaration in `RankingDialog.h`, the single record friendship in `RankingDialog.h`, record-before-collection header order, no duplicate definition/declaration/friend, and no UID0003WT empty-emitter marker. File score remains `88/91`; this child closure does not resolve unrelated file-split and original-name caps.

## Hypothesis

The ranking UI was likely one feature source module rather than seven independent one-class files. `RankingDialog` constructs all ranking child controls, owns the selected-category collection, sends ranking opcode `0x7d` requests, and spawns the reward-info dialog. The event-list, event-scroll, user-list, category-record, category-collection, and reward-info classes are private support types for the same dialog.

Likely structure:

```text
ui/dialogs/RankingDialog.cpp
```

Possible split if the original project used smaller feature files:

```text
ui/dialogs/RankingDialog.cpp
ui/dialogs/RankingRewardInfoDialog.cpp
```

## Proposed Contents

| Entity | Current range | Recovery cue | Role |
| --- | --- | --- | --- |
| [UID:0000BM][RankingDialog](by-class/RankingDialog.md) | `0x00458610-0x004598ac` | `class_RankingDialog.cpp` | Main ranking dialog, category selection, page requests, primary `OnControlCommand(int,int)`, source-ready private [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md) as `RequestRewardClaim()`, historical raw previous/next helper ranges, max-page update, source-ready [UID:0004YX][0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons](by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md), action-button invalidation, and the source-visible `Singleton<RankingDialog>` base contract whose compiler-generated EH destructor copy is non-emitting UID0000Y0. UID0004ZM and UID0004YX own their exact formal CPP bodies; the case-6 reward request is an inlined source call, not a second handwritten body. The old reward-helper UID000420 link is rejected; UID000420 remains the legitimate MapPane identity. |
| [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md) | `0x004598b0-0x0045ae2b` | `class_RankingEventScrollPane.cpp` | Private scrollbar pane for the event/category list. UID0000Y2 remains an accepted `88/91` no-standalone raw constructor/setter marker. The class now emits its exact enum/constant/declaration/tail-field block plus source-ready Y3/Z9/ZA/Y4/ZB, UID0004J0 `SetHighlightedPart`, UID0004J1 `BeginPartInteraction`, UID0004J2 `UpdateActiveInteraction`, executed Y6 `DragToPosition`, and Y7 `ResetInteractionState` through this route. UID0000Y5 is the non-emitting `90/93` split index; exact Y5 children own the three raw bodies and preserve the seven-byte internal alignment island. |
| [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md) | `0x0045ae30-0x0045be67` | `class_RankingEventListPane.cpp` | Scrollable event/category list, category click handling, and event-card drawing. |
| [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) | `0x0045bf60-0x0045c257` | `class_RankingCategoryRecord.cpp` | Parsed ranking category/event record. [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md) is a `92/94` non-emitting sixteen-child aggregate/index, while the `94/95` class declaration and exact child pages provide source output through UID0000BL. The declaration uses standard 36-byte `tm` members, exact partial-constructor sentinels, record-owned `std::vector<RankingUserEntry>`, and the narrow `friend class RankingCategoryCollection;` needed for UID0003WS's proved loaded-category/local-rank/local-score private stores. Complete parser/paint evidence excludes packet writes to the reserved `+0x26c..+0x2ab` tail; it remains copied but unassigned here. Accepted raw setter and exact method children retain their documented source routes. |
| [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md) | `0x0045c260-0x0045d740` | `class_RankingCategoryCollection.cpp` plus helper tail | Category collection with source `std::vector<RankingCategoryRecord> m_records`, selected category id, exact accessors, and implicit outer-vector destruction. UID0003WR and [UID:0003WS][0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse](by-memory/0x0045c560-0x0045cb0a.RankingCategoryCollectionParseInitialCategoryPageResponse.md) are source-ready child definitions; UID0003WS provides the complete category rebuild, matched selection, no-footer optional-local metadata, row/total, helper, and partial-success route. Exact broader memory is [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md), followed by [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md). UID0003WQ, UID0003YR, UID0003YU, and related copy/growth/lifetime/EH helpers remain non-emitting compiler support regenerated by ordinary vector source, not authored helpers. |
| [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) | `0x0045d7e0-0x0045f33a` | `class_RankingRewardInfoDialog.cpp` plus helper islands | Modal reward-info dialog, reward response parser, reward list storage, reward drawing, and reward-entry/item vector helpers. Exact memory includes source-ready [UID:000202][0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit](by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md) as `RankingRewardEntry::RankingRewardEntry()`, source-ready [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) as `ParseFromPacket` plus four accessors, source-ready [UID:000204][0x0045db60-0x0045db9e.RankingRewardEntryItemAt](by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md) as `RankingRewardEntry::ItemAt(int index)`, non-emitting split index [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md), source-ready [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md), [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md) split index with reward children [UID:0003X6][0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth](by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md), [UID:0003X7][0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth](by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md), and [UID:0003X9][0x0045ef50-0x0045efd0.RankingRewardItemVectorClone](by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md), [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md), and [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md). Shared fixed-256 [UID:0003X8][0x0045ef20-0x0045ef50.WideFormatWrapper256](by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md) is reviewed non-emitting MSVC/UCRT support with owner `NONE`, not reward-dialog or `StringUtil` source. |
| [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md) | `0x0045f340-0x0045f9f5` | `class_RankingUserListPane.cpp` | Current ranking page display and local-player rank footer. |
| [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) | `0x0067a7e4` | generated global-data alias | Active ranking dialog singleton. |
| [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md) | `0x0067a7e8` | generated global-data alias | Active ranking reward dialog singleton. |

### RankingCategoryRecord Standard `tm` Source Closure

- The source-ready declaration belongs in `NexusTK/ui/dialogs/RankingDialog.h`, with method definitions in `NexusTK/ui/dialogs/RankingDialog.cpp`; the class page owns the declaration and exact by-memory children own method bodies. This file page groups the feature but has no formal CPP/H channel of its own.
- [UID:0002K3][0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts](by-memory/0x0045bf90-0x0045bfae.RankingCategoryRecordCopyStartTimeParts.md) and [UID:0002K4][0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts](by-memory/0x0045bfb0-0x0045bfce.RankingCategoryRecordCopyEndTimeParts.md) return complete 36-byte standard `tm` values by value. Their apparent explicit output arguments are compiler-lowered hidden structure-return pointers, not developer-authored out parameters.
- [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md) and [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) preserve packet month and full-year values directly rather than applying the C runtime's conventional month-minus-one or year-minus-1900 normalization. The three trailing `tm` fields are copied by the getters but not initialized by these setters.
- `RankingUserListPane::OnPaint` consumes each getter into its own 36-byte local and formats the first six fields directly. It does not read `tm_wday`, `tm_yday`, or `tm_isdst`, which explains why the packed setters can leave those fields untouched without changing the observed UI.
- Historical `RankingDateTimeParts` and `CopyStartTimeParts(out)` / `CopyEndTimeParts(out)` reconstructions are retained as superseded source-shape hypotheses. They captured the byte layout but are not the accepted human-source model after the live `tm` UDT, ABI, setter, and paint evidence were reconciled.

### RankingCategoryRecord GetUserEntryAt Source Closure

- [UID:0002K6][0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt](by-memory/0x0045bfe0-0x0045c01b.RankingCategoryRecordGetUserEntryAt.md) owns the exact method definition in `NexusTK/ui/dialogs/RankingDialog.cpp`; [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) owns the non-const declaration in `RankingDialog.h`. No new source file or pane-owned method is introduced.
- The 59-byte body derives a signed count from the physical vector begin/end slots at `+0x258/+0x25c`, returns null when `count <= index`, and otherwise returns the `0x4c`-scaled row pointer. It contains no lower-bound branch. `RankingUserListPane::OnPaint` is the sole caller at `0x0045f637` and passes exactly `0..9`, null-checking each row before reading rank/name/score.
- The accepted source body uses `std::vector<RankingUserEntry> m_userEntries`, `static_cast<int>(m_userEntries.size())`, and `&m_userEntries[index]`. The old raw `m_userEntriesBegin/m_userEntriesEnd` body and const declaration are retained only as superseded compiler-layout scaffolding; `const_cast`, `at()`, exceptions, unsigned-only comparison, and an added negative-index guard are rejected.
- The corrected half-open endpoint is `0x0045c01b`; `[0x0045c01b,0x0045c020)` is one existing unnamed, untyped, non-code data item of size `5`, containing `cc cc cc cc cc`, with blank comments and zero xrefs. It remains non-emitting alignment: no function, name, type, comment, patch, new source file, or emitted body is introduced, and file placement and file metadata remain unchanged.
- Before this callback, command20963 generated `RankingDialog.cpp`/`.h` reflected the stale raw-field CPP and const H declaration. Validator-owned deferred refresh command20975 now reproduces the corrected UID0002K6 body and non-const declaration without any direct B007 generated-file edit. C23 remains primary-supervisor work because the current category artifacts carry different scoped command authorities and no single coherent post-Gate2/manual-coverage refresh has yet been verified.

### Current RankingRewardInfoDialog Exact Route

[UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md) is now a `91/93`, `RECONSTRUCTABLE:FALSE` split index owned semantically by [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md). It does not represent an empty source method and must not emit a UID0001ZG marker. Exact source output routes through UID0000BP from:

- [UID:0004I7][0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor](by-memory/0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor.md).
- [UID:0004I9][0x0045dda0-0x0045ddc2.RankingRewardInfoDialogOnDialogAction](by-memory/0x0045dda0-0x0045ddc2.RankingRewardInfoDialogOnDialogAction.md).
- [UID:0004IA][0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint](by-memory/0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md).
- [UID:0004IB][0x0045ea20-0x0045ea5e.RankingRewardInfoDialogBuildCloseButtonBoundsRaw](by-memory/0x0045ea20-0x0045ea5e.RankingRewardInfoDialogBuildCloseButtonBoundsRaw.md).
- [UID:0004IC][0x0045ea60-0x0045ead9.RankingRewardInfoDialogSendRewardInfoRequestRaw](by-memory/0x0045ea60-0x0045ead9.RankingRewardInfoDialogSendRewardInfoRequestRaw.md).

Compiler-generated [UID:0004I8][0x0045dd60-0x0045dd9a.RankingRewardInfoDialogConstructorUnwindCleanup](by-memory/0x0045dd60-0x0045dd9a.RankingRewardInfoDialogConstructorUnwindCleanup.md), [UID:0004ID][0x0045eff0-0x0045f018.RankingRewardEntryRangeDestroyCleanupFunclet](by-memory/0x0045eff0-0x0045f018.RankingRewardEntryRangeDestroyCleanupFunclet.md), and [UID:0004IE][0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor](by-memory/0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor.md) remain exact non-emitting children. Existing packet/vector/singleton/thunk children retain their accepted routes, and UID0003X8 remains excluded as owner-`NONE` compiler/UCRT support.

[UID:0003X9][0x0045ef50-0x0045efd0.RankingRewardItemVectorClone](by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md) is now `92/94` source-declared/generated-binary `std::vector<RankingRewardItem>` copy construction routed through UID0000BP and covered by UID0001ZH `m_rewardEntries.push_back(entry)`. It emits one formal no-duplicate marker, not a standalone clone function. The class declaration continues to rely on natural `+0x222..+0x223` alignment before `items +0x224`; executed UID0003X7 remains `93/94`, and the complete X7/UID0001ZJ/UID0004ID rollback support remains compiler-generated from the same source operation.

[UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md) is now `92/94` source-declared/generated-binary `std::vector<RankingRewardEntry>` destruction routed through UID0000BP. It emits one formal covered-by/no-duplicate marker from the existing `RankingRewardItemVector items` and `RankingRewardEntryVector m_rewardEntries` declarations, not a standalone destroy function or explicit entry/dialog destructor body. The marker preserves the exact three destructor/EH xrefs, `m_rewardEntries +0x26c`, `0x230` entry walk, nested `items +0x224` teardown, checked capacity free, triplet clearing, and implicit-special-member source cause while leaving all X7/X9 output unchanged.

[UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md) is now a `92/94` non-emitting split index rather than an empty source emitter. Exact UID0000BP-routed children are [UID:0004J3][0x0045f130-0x0045f15b.RankingRewardEntryRangeDestroy](by-memory/0x0045f130-0x0045f15b.RankingRewardEntryRangeDestroy.md), [UID:0004J4][0x0045f160-0x0045f1c6.RankingRewardItemVectorDestroy](by-memory/0x0045f160-0x0045f1c6.RankingRewardItemVectorDestroy.md), [UID:0004J5][0x0045f1d0-0x0045f285.RankingRewardEntryRangeCopyConstruct](by-memory/0x0045f1d0-0x0045f285.RankingRewardEntryRangeCopyConstruct.md), [UID:0004J6][0x0045f290-0x0045f2f3.RankingRewardItemVectorAllocateStorage](by-memory/0x0045f290-0x0045f2f3.RankingRewardItemVectorAllocateStorage.md), and [UID:0004J7][0x0045f300-0x0045f33a.RankingRewardEntryVectorFreeStorage](by-memory/0x0045f300-0x0045f33a.RankingRewardEntryVectorFreeStorage.md). Each child contributes one formal covered-by marker through UID0000BP, while existing UID0001ZF `items.push_back(item)`, UID0001ZH `m_rewardEntries.push_back(entry)`, implicit destruction, and executed X7/X9/ZK behavior remain the only source causes. No allocator/range/destructor helper body or new source file is introduced.

## Packet And Resource Model

- Ranking packets use opcode `0x7d`.
- Constructor sends subcommand `3` with category/page start values `0,0,10`.
- `RequestRankingPage` sends subcommand `2`, selected category id, start rank `10 * page + 1`, and end rank `10 * (page + 1)`.
- Reward info dialog sends subcommand `5` with the selected category id.
- Reward-claim control case `6` calls private `RankingDialog::RequestRewardClaim()` in human source. The compiler inlines the call in `OnControlCommand`, while source-ready [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md) retains the out-of-line definition. It null-checks `m_categories.GetSelectedRecord()` and sends an exact six-byte request: opcode `0x7d`, subcommand `6`, and one big-endian selected category id. An explicit zero is stored at packet `+6`, outside the six transmitted bytes.
- The paired response is exactly seven bytes for the fields consumed here: opcode/subcommand framing, big-endian category id at packet `+2`, and result byte at `+6`. Dispatcher case `6` calls [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md), then [UID:0004YX][0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons](by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md). Any nonzero result/status byte marks the first matching record state `1`; zero leaves every record unchanged. The UI refresh then disables the reward-claim control.
- Packet builder/helper wording is normalized to [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md), [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Historical labels such as `dword_67A7EC` are retained only as raw-evidence/search aliases.
- Main resources include `WBOARDBK.EPF`, `WBOARDBK.PAL`, `WEBBOARD.EPF`, `WEBBOARD.PAL`, `SUBWIN.EPF`, `SUBWIN.PAL`, `SLIDEBG.EPF`, `SLIDEBG.PAL`, `SCRBUTT.EPF`, `BUTTON.PAL`, and `SYMBOLS.EPF`.

## UID0004ZM RequestRewardClaim Source Route

- Accepted UID0004ZM evidence resolves `[0x00459580,0x004595f3)` as one private `RankingDialog::RequestRewardClaim()` definition in this module. Exact child metadata is `92/94`, owner/emitter UID0000BM, with formal CPP populated and formal H blank for the class-owned declaration reason.
- The retained method and `OnControlCommand` case `6` at `0x00458ac4-0x00458b17` share the `m_categories +0x26c` selected-record lookup/null guard, `0x7d/6` prefix, category-id accessor, BE32 writer, zero store, sender global, and six-byte send. Source contains a call plus one method definition; it does not contain two packet bodies.
- Source placement is the existing `NexusTK/ui/dialogs/RankingDialog.cpp` route near `RequestRankingPage`. Do not create `RawRewardClaimRequestHelper.cpp`, move the method to `RankingCategoryCollection.cpp`, or introduce a packet-utility owner.
- Zero ordinary xrefs and zero VA/RVA/raw-offset pointer hits at the retained start remain documented negative evidence against a surviving direct caller or stored pointer. The exact inline copy supersedes only the earlier inference that those facts required blank CPP.
- The selected collection/record objects are data providers; the dialog owns virtual command dispatch and request policy. The paired seven-byte response remains collection-owned through UID0003WU, followed by dialog-owned UID0004YX UI refresh.
- Exact private spelling `RequestRewardClaim` is inferred rather than original-symbol-proven. That lexical limit and the still-incomplete class header do not block the method's formal CPP or change this file's `88/91` score.

## Boundary Notes

- IDA confirms the ranking-owned island beginning at `0x00458610`. Earlier functions at `0x00457ff0-0x0045860f` are adjacent but not assigned to this file yet.
- `RankingEventScrollPane` constructor/setter island at `0x004598b0-0x00459a59`, exact interaction children at `0x0045a990-0x0045a9ff`, `0x0045aa00-0x0045ab48`, and `0x0045ab50-0x0045ac0f`, and reset method at `0x0045add0-0x0045ae2b` are raw code starts. IDA reports no function objects at those starts, but complete bodies, modeled/inlined active copies, family matches, and exhaustive no-direct-route searches resolve source-ready Y5/Y7 methods. Seven `0xcc` bytes at `0x0045ab49-0x0045ab4f` and twelve at `0x0045adc4-0x0045adcf` remain alignment.
- B004 2026-07-09 accepts [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md) as a RankingEventScrollPane-owned, RankingDialog-routed no-standalone constructor/setter aggregate at `88/91`. Current MCP session `supervisor_nexustk_20260709` confirmed no function objects at the raw starts/returns, no direct xrefs and no pointer-route bytes to the raw starts, the `0x004598b0-0x00459a59` byte range with successor boundary `0x00459a60`, and vtable identities at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`; the repaired layout roles are `+0xf8` `m_scrollSkinIndex`, `+0xfa` `m_scrollStyle`, `+0xfe` `m_scrollPosition`, `+0x100` `m_scrollRange`, and `+0x102/+0x103/+0x104` enabled/highlight/active flags. Its blank formal C++ block and generated empty marker are expected under the accepted no-standalone proof.
- IDA confirms `RankingEventScrollPane` vtables at `0x00610a4c`, `0x00610a98`, and `0x00610ac8`. `RankingEventListPane` constructor `0x0045ae30` allocates a `0x110`-byte child pane and installs those same vtables inline at `0x0045aeb2`, `0x0045aeb8`, and `0x0045aec2`, strengthening this file-level grouping.
- IDA also confirms the broader [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md): `RankingDialog`, `RankingEventListPane`, `RankingRewardInfoDialog`, and `RankingUserListPane` all have primary, secondary, and tertiary vtable views. Use the IDA vtable data for slot ownership.
- `RankingDialog` secondary vtable slot `0x006109f4` points to `0x00459210`, a real packet handler for ranking opcode `0x7d` subcommands `1`, `2`, `3`, and `6`. Nearby `0x00459810` is [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md), an EH-only `source-declared/generated-binary` `Singleton<RankingDialog>` base-destructor instantiation rather than a handwritten helper or class behavior entry point. `0x0045efe0` remains the separately scoped UID0000YA comparator and is unchanged here.
- 2026-05-26 IDA `py_eval` recheck reconfirms `RankingDialog` method boundaries from `0x00458610` through `0x00459840`, `RankingEventListPane` boundaries from `0x0045ae30` through `0x0045be00`, and the six vtable bases/stores for those two classes. Keep the current `class_RankingDialog.cpp` and `class_RankingEventListPane.cpp` owner-pollution caveats, but do not treat the classes themselves as unproved identities.
- The ranking tertiary vtables stop before adjacent UTF-16 resource/label data such as `RewardInfo`, `SUBWIN.EPF`, `Rank`, `SYMBOLS.EPF`, `Total : %d`, and date format strings. Do not read those dwords as virtual slots.
- Recovered `RankingEventScrollPane` output previously had an `OnMouseEvent` scoped marker without a reliable body and missed modeled helpers at `0x0045a400` and `0x0045ac10`. UID0000Y3 now supplies `OnMouseEvent`; executed B003 UID0000Y6 supplies exact `void DragToPosition(int y, int x)` at `90/92`; and B005 now supplies the whole-class declaration, three exact UID0000Y5 child methods, and UID0000Y7 reset. Executed Y6's source block, score, sentinel-controlled geometry, owner factorization, and history are unchanged; only relative coverage `Nested:-4` closes the child indentation.
- B003 UID0001ZA now supplies first-draft `RankingEventScrollPane::OnPaint()` through this file route. Current MCP session `359c7886` confirms the `0x716`-byte primary-vtable body, sole data xref `0x00610a90`, no direct callers, exact `SLIDEBG.EPF/PAL` and `SCRBUTT.EPF`/`BUTTON.PAL` resources, vertical frames `1/0/2`, horizontal frames `4/3/5`, and thumb frames `0/1`. Shared GrafPort/RectBounds/EPFTileContext/ResourceLayout/Surface helpers remain dependencies, not RankingDialog-owned code.
- B004 UID0000Y4 now supplies first-draft `RankingEventScrollPane::HitTestPart(int y, int x)` through this file route. Current MCP session `359c7886` confirms the `0x30c` body, sole vtable data xref `0x00610a94`, no direct callers, y-first call sites, orientation/enable gate, arrow/track/thumb classifications, and the exact horizontal no-code threshold `right - 38`.
- B004 UID0001ZB now supplies first-draft `void RankingEventScrollPane::GetPartRect(RankingScrollPart part, RectBounds *outRect)` at `89/91` through this file route. Evidence-time MCP database `bf5519ae` requests `62006-62019` confirm the exact `0x27b` modeled body and clean pads, all fifteen calls from UID0000Y3/UID0001ZA/UID0000Y5/UID0000Y6/UID0000Y7, only cursor/screen-offset/empty-rectangle callees, sentinel no-write behavior, accepted Point/RectBounds/field contracts, proportional horizontal geometry with control-height span, vertical literal `38`, disabled/no-range fallback, and vertical-only ordered drag clamp. Generic scrollbar/FittingRoom/ScrollCollection ownership, target splitting, horizontal drag, fixed-size Ranking caps, and defensive output initialization remain rejected.
- IDA proves [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md) owns packet parser/helper methods at `0x0045c2a0`, `0x0045c560`, `0x0045cb10`, `0x0045cdc0`, and vector/storage helpers through `0x0045d740`. Its constructor at `0x0045c260` only initializes begin/end/capacity pointers.
- 2026-06-19 B015 accepted [UID:0002K7][0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime](by-memory/0x0045c050-0x0045c0f9.RankingCategoryRecordSetStartTimeFromPackedDateTime.md): the corrected range `0x0045c050-0x0045c0f9` now carries first-draft C++ and is no longer an empty-marker blocker for the RankingCategoryRecord file route.
- 2026-06-20 B001 accepted [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md): the corrected range `0x0045c100-0x0045c1a9` now carries first-draft C++ for `RankingCategoryRecord::SetEndTimeFromPackedDateTime(int packedDate, int packedTime)`, includes the full `c2 08 00` return at PE raw offset `0x5b500`, records the seven-byte `0xcc` postpad before the separate `0x0045c1b0` title-copy setter, and closes the prior paired endpoint/source-quality blocker.
- 2026-07-03 B003 accepted [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md) as a non-emitting sixteen-child aggregate/index. Current MCP session `b010_00032w_20260703` reconfirmed the raw setter starts as no-function/zero-xref but source-shaped bodies with clean padding; the accepted raw setter pages now link to the current RankingCategoryRecord setter files UID000428 [0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex](by-memory/0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex.md), UID000429 [0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId](by-memory/0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId.md), [UID:0004YY][0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode](by-memory/0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode.md), UID00042B [0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText](by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md), and UID00042C [0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount](by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md), not stale MapPane-generated labels.
- IDA proves the secondary-vtable packet handler [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md), reward-entry parser [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md), and vector storage helpers [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md), [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md), and [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md) as ranking reward-info support.
- Historical 2026-06-16 B001 source-quality execution refined the reward helper route: [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md) is a non-emitting split index; reward helper children UID0003X6, UID0003X7, and UID0003X9 route to [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md). The later dedicated review supersedes UID0003X8's old `StringUtil` route with non-emitting compiler/UCRT support.
- Current UID0003X9 closure supersedes only the historical blank/helper-name blocker: exact empty/count/max/allocation/alignment/trivial-copy/publication/failure mechanics are documented on the target, while generated `RankingDialog.cpp` should contain the marker once and retain the single source expression `m_rewardEntries.push_back(entry);`. It must contain no UID0003X9 Empty Emitter Marker, standalone clone body, or explicit `reserved_222` field after waited generation.
- B004 2026-07-03 accepted [UID:000202][0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit](by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md) as source-ready `RankingRewardEntry::RankingRewardEntry()` through [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md). This file remains the `NexusTK/ui/dialogs/RankingDialog.cpp` route only; canonical ownership stays with [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md), and no direct file-root ownership is introduced.
- B005 2026-07-03 accepted [UID:000204][0x0045db60-0x0045db9e.RankingRewardEntryItemAt](by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md) as source-ready `RankingRewardEntry::ItemAt(int index)` through [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md). The route-negative evidence stays a confidence cap and public-API caveat; it does not make [UID:0000MZ] the direct semantic owner.
- B001 2026-07-12 accepted [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) as a source-ready `91/92` parser/four-accessor group through UID0000BP. It now emits exact `ParseFromPacket`, `GetRankStartText`, `GetRankEndText`, raw `GetItemCount`, and `GetSymbolText` bodies while preserving CP_ACP counted strings, signed item count, consumed-byte return, `std::vector<RankingRewardItem>` operations, exact pads, and no-route/original-name confidence caps. No new file owner or direct UID0000MZ body is introduced.
- Earlier recovered `RankingDialog` output incorrectly grouped [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md), Exchange, popup-menu, and generic [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md) helpers with this file. The web-board layout helper `0x0046e2a0`, constructor `0x0046e640`, and response handler `0x0046eaa0` should stay with their documented owners. The exchange outliers `0x004add40` and `0x004ade60` are [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md) and [UID:00014P][0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper](by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md), not RankingDialog methods.
- B004 2026-06-20 confirms the old WebBoard URL escape helper [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) is another generated-output pollution exclusion: it emits through [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), uses old WebBoard escape state/charsets, and has no ranking ownership despite old generated placement artifacts.
- B008 2026-06-19 closes the old-class route: [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) is the fixed-art old variant in [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), with `g_pWebBoardDialogOld`, `WEBBOARD.EPD/PAD`, opcode `0x73`, response byte `0x62`, and old vtable evidence. Treat all old WebBoardDialog constructor/response/helper labels in recovered ranking output as pollution.
- Earlier recovered `RankingEventListPane` output incorrectly grouped generic render/surface helpers around `0x004b9690+`; `0x004b9690`, `0x004b96c0`, `0x004ba450`, and `0x004ba6b0` are now documented as [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md), [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md), and [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md). It also grouped [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) and software-render callback targets from [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md). These belong to shared drawing/rendering modules, not ranking.

## UID0000Y0 Singleton Base Source Route

- The source-visible cause belongs in this module's [UID:0000BM][RankingDialog](by-class/RankingDialog.md) contract: original RTTI proves direct non-virtual `Singleton<RankingDialog>` at `+0x26c`, with empty-base optimization overlapping the category collection at the same displacement.
- Constructor `0x00458610` publishes complete `this` at `0x00458666` while constructing that base, sets EH state `1` at `0x00458677`, then constructs the category collection and sets state `2`. `FuncInfo 0x006589ac` / unwind map `0x006589d0` sends state `1` through `0x005fa138/0x005fa141` to UID0000Y0 and state `2` through `0x005fa146/0x005fa14f` to category destruction.
- Ordinary destructor lowering clears at `0x0045897a`; scalar deleting wrapper clears at `0x0045986d`; constructor adjusted-null fallback clears at `0x0045866d`; UID0000Y0 supplies the fourth and only EH out-of-line copy at `0x00459810`. All are effects of the same Singleton base lifetime, not four source helper calls.
- The 17 xrefs to exact storage `0x0067a7e4` preserve successful publication, failure cleanup, normal/scalar teardown, ranking consumers, and dispatcher duplicate-open prevention. Source output remains the typed [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) definition plus the class base relationship.
- UID0000Y0 is therefore `RECONSTRUCTABLE:FALSE`, non-emitting, and formally blank. Do not add `RankingDialog::ClearSingletonHelper`, an explicit `Singleton<RankingDialog>` specialization, an explicit catch/guard, a late-success assignment, or a one-off source file. The `Singleton<RankingRewardInfoDialog>` and BrowserDialog patterns are comparator evidence; UID0000YA remains unchanged.
- File score `88/91`, projected path `NexusTK/ui/dialogs/`, all unrelated ranking entities/routes, and all existing emitted source remain unchanged. Exact Singleton template-header/static-member spelling is not symbol-proven and remains a bounded lexical uncertainty.

## Assignment-Gate Refresh

The direct file parent clears the corrected `85/85` assignment gate for ranking class children whose own pages also meet the gate. Current completion/confidence is `88/91`: the page has a full feature-module inventory, exact method/data child references, ranking packet/resource model, explicit owner-pollution exclusions, refreshed aggregate/vtable support, and source-ready exact children including UID0004ZM. The exact original file split/name, remaining raw helper source shapes, complete class headers, and final member/helper names remain bounded caveats.

Supporting evidence:

- [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md) documents the exact `0x00610980-0x00610e38` ranking read-only-data child at `87/91`, including `RankingEventListPane` RTTI/vtables at `0x00610ad0-0x00610b74`, constructor/destructor store xrefs, and the `SUBWIN` resource boundary.
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) documents the ranking vtable family at `86/92`, including exact RankingDialog primary `+0x48` `OnControlCommand(int,int)` and the `RankingEventListPane` primary, secondary, and tertiary slot anchors.
- [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) documents the singleton global at `85/90`; [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) records the exact storage refs.
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) covers the executable ranking island at `87/90`, from `RankingDialog` construction through `RankingUserListPane`, with live constructor, packet-handler, singleton, exact-child, raw-helper, and padding checks.
- The non-ranking WebBoard, popup, dialog animation, and generic render helper ranges are explicitly excluded above, so class children can attach to this file without inheriting those generated-output mistakes.

2026-06-16 A002 live support refresh:

- Active IDA MCP session `b001_selflookpane_0001H7_20260616` reports `NexusTK.exe.i64`, image base `0x00400000`, Hex-Rays ready.
- That evidence pass's `lookup_funcs` reconfirmed the core ranking method map and then-current custom IDA names `RankingDialog_HandleRankingPacket`, `RankingDialog_ClearSingletonHelper`, and `RankingDialog_ScalarDeletingDestructor`. Later UID0000Y0 evidence again observes raw `sub_459810`; the old helper rename is historical search provenance, not current source identity.
- `xrefs_to 0x00458610` shows the single command-dispatch constructor call at `0x005bd2ab`; `xrefs_to 0x00459210` shows the secondary-vtable slot at `0x006109f4`; `xrefs_to 0x0067a7e4` shows all 17 singleton refs.
- `analyze_function 0x00459210` reconfirms opcode `0x7d` subcommand dispatch for category/page/reward updates. Raw scroll-pane starts `0x004598b0`, `0x0045a990`, and `0x0045add0` still have no IDA function object and no inbound xrefs, so their source shape remains a real blocker rather than an uninvestigated caveat.
- Score moves to `86/88`: the parent/source grouping and support chain are now stronger than the older `85/86` gate refresh, but final original filename versus compact feature split, private member names, and raw helper source names still cap the file below final-source levels.

2026-06-23 B001 accepted source-quality implementation:

- Current MCP session `80de0a67` reports active `NexusTK.exe.i64` with Hex-Rays ready and reconfirms the ranking constructor, packet handler, singleton refs, vtable-backed methods, raw helper starts, category setter raw bodies, reward packet handler, and shared formatter exclusion.
- The source module remains `ui/dialogs/RankingDialog.cpp`. A separate broad `RankingRewardInfoDialog.cpp` is rejected as lower probability because the reward dialog is a private modal child sharing ranking opcode `0x7d`, selected category state, singleton lifecycle, and helper/storage routes with this feature module.
- One-class files for each private class are rejected for current reconstruction because they miss raw helper islands and repeat known generated-output pollution. The class pages still own class declarations/method inventories, while this file page is the source route.
- `RankingDialog` class ownership is intentionally not promoted to all children: [UID:0000BM][RankingDialog](by-class/RankingDialog.md) owns its direct methods/helpers only; sibling private classes route through this file.
- Packet sender/writer/queue helpers are dependencies only, not owners. Use `PacketBufferWriteUInt8`, `PacketBufferWriteUInt32BE`, `g_packetSender`, and `QueueAndSendPacket` in support text instead of raw `dword_67A7EC`-style labels.
- Completion/confidence move to `87/90`: the file now has accepted exact helper inventories and normalized packet dependencies. UID0004YX's inherited control APIs are subsequently resolved; final original filename/fine split and unrelated class/helper/layout cleanup still keep this broader route below final-audit scores.

## 2026-07-31 B007 UID0004YX Source-Ready Child

- [UID:0004YX][0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons](by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md) is now a `92/94` source-bearing method child through [UID:0000BM][RankingDialog](by-class/RankingDialog.md), not an inherited-API-blocked empty emitter.
- Live MCP session `f608d7c2`, pre-transaction IDB SHA256 `CF18895C73C8ED240D9B1351AFBD66E73E8C9D6F56F193479ECCA4FEEE2C7F96`, proves `[0x004596b0,0x004597ae)`, calls from reward-status handling and max-page recomputation, and a receiver-only `void` source signature despite the historical decompiler EDI-argument/pointer-return artifacts.
- The exact method uses `m_categories.GetSelectedRecord()` and the accepted `DialogPane::GetChild<T>` plus `ControlPane::Enable/Disable/IsEnabled` surfaces. Controls `3/4` are previous/next `ImageButtonControlPane` objects; controls `5/6` are `FittingRoomTextButtonControlPane` objects labeled `RewardInfo`/`GetReward`.
- State `0` enables reward claim, states `1/2` disable it, other states preserve it, and a null selected record disables both reward controls. Navigation uses `m_currentPage/m_maxPage`, null checks, and transition-only mutations.
- The exact child formal CPP is emitted through existing `NexusTK/ui/dialogs/RankingDialog.cpp`. No new ButtonState, RewardButton, category-record, generic-control, or reward-dialog source file is warranted.
- Historical note: the earlier blank disposition was correct while only raw List/vtable lowering was available. Current DialogPane/ControlPane declarations resolve that one child-specific blocker. UID000427 and unrelated raw helpers retain their own separate dispositions.
- Supervisor catalog entry `0379` saved the source-facing IDA handoff without changing file routing at dated checkpoint SHA256 `4B5F2EC3F83106BAC18640D079C51CD2E2FB56797577EFE7D994EF483D9A696A`, `143,192,707` bytes, saved `2026-07-31T04:26:38.9922636-04:00`; the exact backup SHA256 `CF18895C...2C7F96` is dated prestate. Authoritative current saved IDB is SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143,192,751` bytes, saved `2026-07-31T06:21:13.3464834-04:00`, session `f608d7c2`; bounded read-only target/helper/getter/predecessor/successor readback found no UID0004YX drift.
- Current target IDA identity is `RankingDialog__UpdateRewardAndNavigationButtons` with `void __thiscall(RankingDialog *this)` and accepted function-regular comment. Current selected-record helper identity is `RankingCategoryCollection__GetSelectedRecord` with `RankingCategoryRecord *__thiscall(const RankingCategoryCollection *this)` and accepted function-regular comment. Both retain their exact ranges, xrefs, bytes, return-only frames, and blank non-regular comment channels.
- The transaction created only an incomplete zero-member `RankingCategoryCollection` declaration and preserved incomplete `RankingDialog`/`RankingCategoryRecord` types. It did not create a separate collection source file, concrete layout, new member, or new owner route.
- File metadata remains `88/91`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`; all existing feature grouping, singleton/vtable evidence, pollution exclusions, and unrelated source-placement history remain unchanged.

## 2026-06-30 B006 Narrowed Empty-Emitter Callback

Agent-B006's revised `0000MZ-RankingDialog-empty-emitter-family-source-quality.md` report was accepted only for the narrowed C01-C11 subset. The withdrawn broad 36-row cleanup should not be applied from that rejected draft.

Current MCP provenance used for this callback:

- Active listener `http://127.0.0.1:13337/mcp`, database `supervisor_resume_20260629`.
- Request id `2004`, `server_health`: status `ok`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`.
- Request ids `2005-2012` prove [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md) matches the accepted FittingRoom default-false virtual pattern: `0x00459cd0 -> sub_459CD0 size 0x5`, one vtable data xref at `0x00610aa0`, decompile `return 0`, bytes `32 c0 c2 04 00 cc cc cc`, and disassembly `xor al, al; retn 4`. The accepted comparator `0x0041da60` has the same body bytes and vtable-only shape.
- Request id `2013` reconfirms [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md) as a `0x4c` `RankingUserEntry` append through record offsets `+0x258/+0x25c/+0x260`, with one caller at `0x0045cd5d` and growth-helper callee `sub_45D1B0` only when full.
- Request ids `2015-2016` reconfirm [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md) and [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md): opcode `0x7d`/subcommand `5`, selected-category validation through `g_pRankingDialog`, parser call, `0x230` reward entries, `0x208` reward-item rows, and temporary nested-vector cleanup. The then-current parser-source blockers are historical and resolved by the accepted B001 UID0001ZF callback.
- Request ids `2006` and `2010` reconfirm [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) has 17 data xrefs and zero storage at `0x0067a7e4`, and [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md) has 6 data xrefs and zero neighboring singleton storage.

Accepted immediate source-output changes from the narrowed callback:

- [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md) now emits `RankingEventScrollPane::DefaultVirtualFalse(int)` as the exact always-false first-draft body. The inherited interface's original method spelling remains inferred, but that caveat no longer blocks first-draft output because the FittingRoom default-false pattern was already accepted.
- Historical B006 state: [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) then emitted only `RankingRewardItem` and `RankingRewardEntry` support declarations, while UID0001ZH retained a no-code decision. The 2026-07-12 UID0001ZG callback and subsequent Gate 1 additive repair supersede that limited state with `std::vector` aliases, the full dialog declaration, six exact source-method behaviors, and source-emitting UID0001ZH.
- [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md) retains its formal no-code comment because it still lacks an accepted record-owned user-entry vector abstraction. UID0001ZF no longer belongs in this no-code inventory: accepted PacketBuffer/vector APIs and exact counted-string/accessor source now emit through UID0000BP. [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md) likewise emits `HandlePacketEvent(Event *event)` through UID0000BP.
- [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) and [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md) emit source-level pointer definitions with source-visible forward declarations. [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md) and [UID:00028V][0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog](by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md) are non-emitting exact storage support pages so they do not duplicate the by-global source output.

Follow-up rows not accepted in this callback:

- Broad aggregate/index pages such as [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md), [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md), [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md), and [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) remain plausible non-emitting candidates but were deliberately excluded from this narrowed implementation.
- Scroll-pane methods besides [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md) were historically blocked by event/geometry/scroll-part/invalidation/member names. UID0000Y3 `OnMouseEvent`, UID0001ZA `OnPaint`, UID0000Y4 `HitTestPart`, UID0001ZB `GetPartRect`, UID0004J0 `SetHighlightedPart`, UID0004J1 `BeginPartInteraction`, UID0004J2 `UpdateActiveInteraction`, UID0000Y6 `DragToPosition`, and UID0000Y7 `ResetInteractionState` now have separately accepted source bodies. UID0000Y2 alone retains its page-specific blank/no-standalone disposition; do not infer constructor/setter APIs from the completed class method surface.
- Layout/vtable/read-only-data/container helper pages such as [UID:0001ZE][0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper](by-memory/0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper.md), [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md), [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md), [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md), [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md), [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md), [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md), and [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md) remain follow-up support rows until separately accepted.

This file's older [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) broad executable-island report should be read as support and duplicate-avoidance evidence, not as a direct [UID:0000MZ] source-quality closeout or permission to emit a monolithic ranking island body.

## UID0002KA Reset-Before-Page-Request Contract

[UID:0002KA][0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries](by-memory/0x0045c240-0x0045c256.RankingCategoryRecordResetUserEntries.md) is a class-owned `RankingCategoryRecord::ResetUserEntries()` method in this source module. Its exact body is `[0x0045c240,0x0045c257)`, with one call at `0x004594f7` inside `RankingDialog::RequestRankingPage`. The next instruction at `0x004594fc` overwrites `EAX`, so the residual register value from the compiler lowering is ignored and the human source method returns `void`.

The reset clears the selected record's `std::vector<RankingUserEntry> m_userEntries` by setting physical end `+0x25c` back to begin `+0x258`, preserves begin and capacity `+0x260`, and sets `m_localPlayerRank` at `+0x268` to `-1`. It does not free vector storage or change the selected category id, loaded-rows category id, total count, reserved footer tail, or local-player score. Storage release remains the separate vector-destructor path at `0x0045d5f0`.

After `record->ResetUserEntries();`, `RequestRankingPage` emits opcode `0x7d`, subcommand `2`, the selected category id, and the one-based inclusive rank interval `10 * page + 1` through `10 * (page + 1)`. The response parser validates that category, repeats the clear/rank-reset lowering before appending replacement `0x4c`-byte rows, and optionally replaces local-player rank/footer metadata. The initial-page parser performs the same logical reset while loading subcommand `3` data. `RankingUserListPane::OnPaint` displays the local-player footer only when `m_localPlayerRank > 0`.

Historical descriptions of `+0x268` as a selected-user index and of reset as handwritten raw begin/end/capacity assignments are retained only as disproved compiler-layout interpretations. The source route is `NexusTK/ui/dialogs/RankingDialog.cpp` with the declaration in `RankingDialog.h` through [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md); this by-file page remains a grouping/source-placement owner and does not duplicate the child method body.

## UID0003YR Outer Category Vector Source Route

[UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md) is the 133-byte final teardown specialization for [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)'s outer category-record vector. Its authored source cause belongs in `NexusTK/ui/dialogs/RankingDialog.h` as `std::vector<RankingCategoryRecord> m_records`; normal implicit `RankingCategoryCollection` destruction in `RankingDialog.cpp/.h` supplies the lifetime route. No definition or declaration named `RankingCategoryRecordVectorDestroy` belongs in recovered source.

The specialization is reached only through [UID:0003WQ][0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk](by-memory/0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk.md), whose incoming lifetime paths are exactly `0x00458973`, `0x00459866`, and `0x005fa14f`. UID0003YR walks `[begin,end)` at exact `0x2b0` record stride, calls the nested UID0003YT teardown for each record's `m_userEntries` at `+0x258`, validates and frees outer storage through the MSVC small/large allocation branches, and clears begin/end/capacity. Exact target and thunk body hashes are `BD68BC2529D22C1E3F240894411081A291B663A38B45EC1B1130BB149034C24D` and `BF61252F1E61B859B1994B42177DBE6C9E3859519FCFEA28A27E51A8FC5F11D4`.

The same source model makes [UID:0003WW][0x0045ce40-0x0045ce57.RankingCategoryCollectionGetCount](by-memory/0x0045ce40-0x0045ce57.RankingCategoryCollectionGetCount.md) use `m_records.size()` and [UID:0003WZ][0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex](by-memory/0x0045cf00-0x0045cf44.RankingCategoryCollectionGetByIndex.md) return `&m_records[index]` after the exact signed-short bounds check. [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) emits before UID0000BK so the element type is complete when the C++03 standard vector is declared.

UID0003YR and UID0003WQ remain semantically owned by UID0000BK but are `RECONSTRUCTABLE:FALSE`, blank-emitter, and blank in formal CPP/H. Any generated UID0003YR empty-emitter marker is stale metadata output to be removed only by the supervisor-owned coherent generated refresh after ordinary/manual/IDA verification. This file page neither edits generated output nor duplicates binary helper code; the rebuilt period-appropriate toolchain must nevertheless reproduce the exact nested destruction, allocator validation, free, and triplet clearing.

## UID0003YT Header-Owned Vector Teardown Route

[UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md) is the 99-byte final storage-release specialization for `RankingCategoryRecord::m_userEntries`. Its authored source cause is the existing `std::vector<RankingUserEntry> m_userEntries` declaration in `RankingDialog.h` and ordinary class lifetime; no standalone target definition or declaration belongs in `RankingDialog.cpp` or `RankingDialog.h`.

The binary specialization receives the physical begin/end/capacity triplet at record offsets `+0x258/+0x25c/+0x260`. A null begin returns. Non-null storage uses the `0x4c` row stride to recover the capacity allocation span, frees small allocations directly, and for spans at least `0x1000` recovers the raw allocation from `begin[-1]` and validates `(begin - raw - 4) <= 0x1f`. Failure reaches exact runtime symbol `__invalid_parameter_noinfo_noreturn`; success calls `sub_5C7526` and clears all three triplet slots. No row-destructor loop exists because `RankingUserEntry` is trivial.

Nine record-lifetime and compiler-EH sites call the specialization. The `0x45bf56` route belongs to an existing `[0x0045bf50,0x0045bf5b)` tail chunk owned by `sub_45C2A0`, not an ownerless fragment; the former ownerless interpretation is retained only as rejected history. UID0003YT therefore remains semantically owned by [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md) but is `RECONSTRUCTABLE:FALSE`, with blank emitter and formal CPP/H.

Any generated UID0003YT empty-emitter marker is a consequence of stale source metadata rather than missing authored source. Only the supervisor-owned coherent generated refresh may remove that marker after ordinary metadata is accepted. This by-file page stays at `88/91` and remains a grouping/source-placement route; it must not duplicate a raw helper body. Runtime reconstruction must nevertheless reproduce the exact `0x4c`-stride capacity release, aligned large-allocation validation, free, and triplet clear through the chosen period-appropriate container/toolchain.

## UID0003YS Collection-Growth Rollback Route

[UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md) is another non-emitting compiler artifact whose physical source route is this ranking module. It is generated by [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)'s outer category-record vector growth, while [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)'s `std::vector<RankingUserEntry> m_userEntries` supplies the nested lifetime operation.

The 43-byte body walks a half-open range of `0x2b0`-byte records and calls UID0003YT on each `record + 0x258`. Its only incoming call, `0x45d187`, is in the growth helper's post-return EH tail; the tail then frees failed destination storage at `0x45d195` and rethrows at `0x45d19e`. There are no target data xrefs or VA/RVA/raw-offset pointer routes, and exact `0xcc` fences isolate the helper from its neighbors.

The human source in `RankingDialog.cpp/.h` should contain ordinary category-record vector operations and the existing nested vector member, not a definition or declaration named `RankingCategoryRecordRangeDestroyUserEntries`. UID0003YS is therefore `94/95`, `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal CPP/H under UID0000BK semantic ownership. The descriptive name is documentation/IDA terminology only.

Historical generated command `000000021217` contained UID0003YS only as an Empty Emitter Marker because the former target metadata incorrectly retained an emitter route. Dated report-time callback receipt command `000000021232` recorded a scoped refresh/stamp of `RankingDialog.cpp`/`.h`; at that snapshot `RankingDialog.cpp` contained no UID0003YS marker or helper body and `RankingDialog.h` contained no UID0003YS declaration or duplicate code. Dated report-time repair receipt command `000000021253` validated this by-file page with generated refresh explicitly skipped, so neither receipt is permanent generated or manual authority. Current generated/manual authority requires direct primary-supervisor refresh and verification. The substantive accepted result remains the non-emitting UID0003YS source route, while this file page remains `88/91` and preserves all unrelated ranking contents and pollution exclusions.

## UID0003X0 Outer Category Vector Growth Source Route

[UID:0003X0][0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth](by-memory/0x0045cf50-0x0045d1ad.RankingCategoryRecordVectorInsertWithGrowth.md) is the exact 605-byte compiler specialization generated by [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)'s `std::vector<RankingCategoryRecord> m_records`. Its physical source route is the existing `NexusTK/ui/dialogs/RankingDialog.cpp` parser definitions plus the `RankingDialog.h` class declaration; it is not a separate source file, class method, allocator utility, or global helper.

The two source-authored parser append sites explain all reachability. UID0003WR takes its fast deep-copy path at `0x45c4f1` and its capacity-exhausted UID0003X0 path at `0x45c502`; UID0003WS mirrors those paths at `0x45c7cb` and `0x45c7dc`. Each then advances the outer vector end and destroys the local record's nested user-entry vector at `0x45c514` or `0x45c7ee`. Recovered source should express only the ordinary append of the stack-built record to `m_records`.

The specialization's `0x2b0` stride, one-half growth, small/large 32-byte-aligned allocation policy, inserted/prefix/suffix deep-copy construction, old-record `+0x258` nested teardown, and UID0003YS/UID0001ZE cleanup/rethrow tail are exact runtime requirements regenerated by the compatible standard library/toolchain. They are not authored source APIs. No `RankingCategoryRecordVectorInsertWithGrowth` declaration belongs in `RankingDialog.h`, and no helper definition or raw allocator/EH body belongs in `RankingDialog.cpp`.

UID0003X0 is therefore `94/95`, semantically owned by UID0000BK, `RECONSTRUCTABLE:FALSE`, non-emitting, and blank in formal CPP/H. This by-file page remains `88/91`, `CANONICAL_OWNER:FILE`, and the broad source-placement/grouping owner. Earlier direct-emitter/source-helper wording is retained only as corrected historical reconstruction; all unrelated ranking routes and existing output-pollution exclusions remain intact.

## UID0003YU Uninitialized Range-Copy Source Route

[UID:0003YU][0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep](by-memory/0x0045d660-0x0045d6d6.RankingCategoryRecordRangeCopyConstructDeep.md) is the exact 118-byte MSVC/Dinkumware uninitialized range-copy specialization generated inside UID0003X0 while growing `RankingCategoryCollection::m_records`. Its physical source route is the same existing `NexusTK/ui/dialogs/RankingDialog.cpp` parser implementation plus the `RankingDialog.h` declaration of `std::vector<RankingCategoryRecord> m_records`; it is not a source method, global helper, allocator utility, or separate source file.

UID0003X0 is its complete incoming route. Calls at `0x45d0c8` and `0x45d0d9` construct prefix and suffix half-open ranges around the newly inserted record. UID0003YU iterates from `first` to `last`, invokes UID0003X4 at `0x45d6a8` to deep-copy each `RankingCategoryRecord`, advances source and destination by exact `0x2b0` stride, and returns the resulting destination end. An empty range returns the original destination. Because UID0003X4 deep-copy constructs `m_userEntries`, the operation is not byte copy and recovered source must not use `memcpy`.

The compiled helper tracks the constructed prefix under SEH. A failed element copy reaches the shared cleanup through `0x5fa330 -> 0x5fa333`, destroys nested user-entry vectors for the already constructed half-open range, performs the cookie check, and continues unwinding. No data xref, encoded pointer, vtable slot, callback route, or gameplay API reaches the helper. The source-visible operation remains the ordinary parser append/growth of the stack-built record in `m_records`; standard C++03 vector machinery regenerates prefix/suffix copy, returned-end bookkeeping, and cleanup.

UID0003YU is therefore `94/95`, semantically owned by UID0000BK, `RECONSTRUCTABLE:FALSE`, non-emitting, and blank in formal CPP/H. This file page remains `88/91`, `CANONICAL_OWNER:FILE`, and the source-placement root. No `RankingCategoryRecordRangeCopyConstructDeep` declaration/body, raw vector-triplet manipulation, explicit EH loop, or standalone helper file belongs in `RankingDialog.cpp/.h`. Earlier source-declared/emitting helper interpretations remain only as corrected history.

## UID0003X4 Implicit Record Copy Source Route

[UID:0003X4][0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep](by-memory/0x0045d420-0x0045d4f8.RankingCategoryRecordCopyConstructDeep.md) is the exact 216-byte compiler-generated implicit copy constructor for [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md). Its authored source cause is already complete in `NexusTK/ui/dialogs/RankingDialog.h`: the record's fixed members plus `std::vector<RankingUserEntry> m_userEntries`. No explicit copy-constructor declaration belongs in the header.

The body copies fixed record spans `+0x000..+0x257` and `+0x264..+0x2af`, and deep-copy constructs only the vector at physical `+0x258/+0x25c/+0x260` through UID0003X3. Five call sites come entirely from ordinary `std::vector<RankingCategoryRecord> m_records` operations: parser fast appends at `0x45c4f1`/`0x45c7cb`, growth inserted/end copies at `0x45d07b`/`0x45d0a9`, and range copy at `0x45d6a8`. Caller-owned end advances, temporary teardown, partial-range cleanup, failed-storage free, and rethrow preserve the required nested lifetime and strong exception guarantee.

The recovered module should therefore contain ordinary parser append/range source in `RankingDialog.cpp` and the existing class declarations in `RankingDialog.h`. It must not add `RankingCategoryRecordCopyConstructDeep` as a function, member, template helper, raw copy body, new translation unit, or duplicate source marker. The chosen period-appropriate compiler and standard library must regenerate equivalent memberwise copy, nested allocation/copy, throw, and cleanup behavior.

UID0003X4 is reviewed `94/95`, semantic owner UID0000BL, `RECONSTRUCTABLE:FALSE`, non-emitting, and blank in target CPP/H. A generated UID0003X4 `Empty Emitter Marker` reflects the prior true/emitter metadata and must disappear only during the supervisor-owned coherent refresh; no UID0003X4 declaration or standalone body should appear in `RankingDialog.h` or `RankingDialog.cpp`. This by-file page remains `88/91`, `CANONICAL_OWNER:FILE`, and preserves every unrelated ranking route and pollution exclusion.

## Migration Notes

Keep migration as a dry-run planning exercise until the non-ranking helper pollution has been removed or re-owned. Before any real migration, confirm that WebBoard, exchange, popup-menu, generic dialog animation, and render helper rows are not carried into `RankingDialog.cpp`.

## Cross-References

- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BN][RankingEventListPane](by-class/RankingEventListPane.md)
- [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md)
- [UID:0000BQ][RankingUserListPane](by-class/RankingUserListPane.md)
- [UID:0000BL][RankingCategoryRecord](by-class/RankingCategoryRecord.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0003WQ][0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk](by-memory/0x0045c290-0x0045c295.RankingCategoryCollectionDestructorThunk.md)
- [UID:0003YR][0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy](by-memory/0x0045d530-0x0045d5b5.RankingCategoryRecordVectorDestroy.md)
- [UID:0003YS][0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries](by-memory/0x0045d5c0-0x0045d5eb.RankingCategoryRecordRangeDestroyUserEntries.md)
- [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md)
- [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md)
- [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md)
- [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md)
- [UID:0001ZA][0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint](by-memory/0x00459ce0-0x0045a3f5.RankingEventScrollPaneOnPaint.md)
- [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md)
- [UID:0001ZB][0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect](by-memory/0x0045a710-0x0045a98a.RankingEventScrollPaneGetScrollRegionRect.md)
- [UID:0000Y5][0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers](by-memory/0x0045a990-0x0045ac0f.RankingEventScrollPaneRawHoverDragHelpers.md)
- [UID:0004J0][0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw](by-memory/0x0045a990-0x0045a9ff.RankingEventScrollPaneSetHighlightedPartRaw.md)
- [UID:0004J1][0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw](by-memory/0x0045aa00-0x0045ab48.RankingEventScrollPaneBeginPartInteractionRaw.md)
- [UID:0004J2][0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw](by-memory/0x0045ab50-0x0045ac0f.RankingEventScrollPaneUpdateActiveInteractionRaw.md)
- [UID:0000Y6][0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition](by-memory/0x0045ac10-0x0045adc3.RankingEventScrollPaneDragToPosition.md)
- [UID:0000Y7][0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState](by-memory/0x0045add0-0x0045ae2b.RankingEventScrollPaneRawResetState.md)
- [UID:0001VO][RankingEventScrollPaneLayout](by-type/by-struct/RankingEventScrollPaneLayout.md)
- [UID:0001YK][RankingEventScrollPaneVtables](by-type/by-vtable/RankingEventScrollPaneVtables.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000Y0][0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor](by-memory/0x00459810-0x0045981a.RankingDialogSingletonBaseDestructor.md)
- [UID:0000Y1][0x0045981b-0x00459830.RankingDialogAdjustorThunks](by-memory/0x0045981b-0x00459830.RankingDialogAdjustorThunks.md)
- [UID:0004ZM][0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper](by-memory/0x00459580-0x004595f3.RankingDialogRawRewardClaimRequestHelper.md)
- [UID:0003WU][0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse](by-memory/0x0045cdc0-0x0045ce2b.RankingCategoryCollectionApplyRewardClaimStatusResponse.md)
- UID000422 [0x00459600-0x00459623.RankingDialogRawPreviousPageHelper](by-memory/0x00459600-0x00459623.RankingDialogRawPreviousPageHelper.md)
- UID000424 [0x00459630-0x00459655.RankingDialogRawNextPageHelper](by-memory/0x00459630-0x00459655.RankingDialogRawNextPageHelper.md)
- UID000425 [0x00459660-0x004596a1.RankingDialogUpdateMaxPageFromSelectedRecord](by-memory/0x00459660-0x004596a1.RankingDialogUpdateMaxPageFromSelectedRecord.md)
- [UID:0004YX][0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons](by-memory/0x004596b0-0x004597ae.RankingDialogUpdateRewardAndNavigationButtons.md)
- UID000427 [0x004597b0-0x00459804.RankingDialogInvalidateActionButtons](by-memory/0x004597b0-0x00459804.RankingDialogInvalidateActionButtons.md)
- UID000428 [0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex](by-memory/0x0045c020-0x0045c02d.RankingCategoryRecordSetListIndex.md)
- UID000429 [0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId](by-memory/0x0045c030-0x0045c03d.RankingCategoryRecordSetCategoryId.md)
- [UID:0004YY][0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode](by-memory/0x0045c040-0x0045c04d.RankingCategoryRecordSetStateCode.md)
- UID00042B [0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText](by-memory/0x0045c1b0-0x0045c1cb.RankingCategoryRecordSetTitleText.md)
- UID00042C [0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount](by-memory/0x0045c1d0-0x0045c1e0.RankingCategoryRecordSetTotalRankCount.md)
- [UID:0000Y8][0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks](by-memory/0x0045bddd-0x0045bdf2.RankingEventListPaneAdjustorThunks.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)
- [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md)
- [UID:0000YC][0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks](by-memory/0x0045f97d-0x0045f992.RankingUserListPaneAdjustorThunks.md)
- [UID:0000Y9][0x0045bf60-0x0045c257.RankingCategoryRecord](by-memory/0x0045bf60-0x0045c257.RankingCategoryRecord.md)
- [UID:0001ZC][0x0045c260-0x0045d4f8.RankingCategoryCollection](by-memory/0x0045c260-0x0045d4f8.RankingCategoryCollection.md)
- [UID:0001ZD][0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers](by-memory/0x0045d530-0x0045d740.RankingCategoryVectorStorageHelpers.md)
- [UID:0003YT][0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy](by-memory/0x0045d5f0-0x0045d653.RankingUserEntryVectorDestroy.md)
- [UID:0001ZE][0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper](by-memory/0x0045d750-0x0045d78a.RankingCategoryRecordVectorFreeHelper.md)
- [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md)
- [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md)
- [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
- [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md)
- [UID:0003X6][0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth](by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md)
- [UID:0003X7][0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth](by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md)
- [UID:0003X8][0x0045ef20-0x0045ef50.WideFormatWrapper256](by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md)
- [UID:0003X9][0x0045ef50-0x0045efd0.RankingRewardItemVectorClone](by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md)
- [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md)
- [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md)
- [UID:0001VN][RankingCategoryRecordLayout](by-type/by-struct/RankingCategoryRecordLayout.md)
- [UID:00012U][0x0049eac0-0x0049f081.DialogPaneSlideAnimation](by-memory/0x0049eac0-0x0049f081.DialogPaneSlideAnimation.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000164][0x004b96c0-0x004b9768.GrafPortGetClipRect](by-memory/0x004b96c0-0x004b9768.GrafPortGetClipRect.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md)

## Changes

### 2026-08-14 - B003 UID0003WT selected-row source route

- Added exact method-definition/declaration ownership, dispatcher/request pairing, stale/no-match guards, clear/rank baseline, signed optional/count/cursor behavior, no-reserved-tail result, CP_ACP `0x4c` row construction, final-total ordering, partial-success semantics, helper boundary, body/pad identity, and the existing narrow-friend route.
- Added the expected one-definition/one-declaration/one-friend generated result with no duplicate or UID0003WT empty marker.
- Preserved file metadata `88/91`, all UID0003WS work, every unrelated ranking route, and existing source-placement/pollution history.

### 2026-08-14 - B001 UID0003WS initial-page source route

- Added the complete method-definition/declaration ownership, exact record friendship, header positions, signed category/row packet behavior, selection/local/no-tail/total commits, helper ownership, partial-success failure model, and unique RankingDialog.cpp/.h route.
- Added the expected one-definition/one-declaration/one-friend generated result with no duplicate or UID0003WS empty marker, and corrected the historical UID0003WR direct-CRT include route to the accepted MemoryMan preamble.
- Preserved file metadata `88/91`, every unrelated ranking child/source route, and all existing history and pollution exclusions.

### 2026-08-14 - B005 UID0003WR category-list source route

- Added the exact parser definition/header ownership, signed count/cursor and wire/title behavior, partial record constructor, successful-prefix failure semantics, compiler-helper non-emission, shared PacketBuffer UInt16/UInt32 dependency, include scaffold, and unique RankingDialog.cpp/.h route.
- Retained file metadata `88/91`, all existing ranking child/source details, and historical generated/source-route evidence.

### 2026-08-06 - B002 UID0003YU non-emitting source route

- Added exact RankingDialog.cpp/.h placement for the two-call prefix/suffix uninitialized range-copy specialization generated by `RankingCategoryCollection::m_records` growth.
- Preserved the `0x2b0` deep-copy loop through UID0003X4, returned destination end, constructed-prefix cleanup through UID0003X5, negative reachability, and permanent no-standalone-helper source boundary.
- Preserved file `88/91`, file ownership, `NexusTK/ui/dialogs/`, every unrelated ranking route, and all existing formal source and pollution exclusions.

### 2026-08-06 - B007 UID0003X4 implicit-copy source route

- Added the exact record-class/header source cause, fixed-versus-nested copy behavior, five parser/growth/range uses, lifetime/EH requirements, no-explicit-special-member decision, and generated-marker pollution exclusion.
- Preserved file `88/91`, `CANONICAL_OWNER:FILE`, projected `NexusTK/ui/dialogs/` route, all existing class/method output, and unrelated ranking-family/pollution history; no helper declaration/body or generated file was added.

### 2026-08-06 - B002 UID0003X0 non-emitting source route

- Added the exact two parser fast/slow append routes, `m_records` source cause, `0x2b0` growth/deep-copy/nested-lifetime behavior, aligned allocation/free and EH rollback constraints, and RankingDialog.cpp/.h placement.
- Rejected a standalone helper definition/declaration or helper translation unit while preserving file metadata `88/91`, `CANONICAL_OWNER:FILE`, all unrelated ranking-family content, and prior pollution exclusions.

### 2026-08-05 - B007 UID0003YR outer-vector source route

- Preserved file metadata at `88/91`, `CANONICAL_OWNER:FILE`, the `NexusTK/ui/dialogs/` route, and all unrelated ranking-family contents.
- Added `std::vector<RankingCategoryRecord> m_records`, implicit collection destruction, exact accessor source forms, header emission order, the destructor thunk/outer teardown ranges, callers, body hashes, nested lifetime, allocator validation, and non-emitting source boundary.
- Kept generated-marker removal and coherent source/header refresh supervisor-owned; no raw helper body or declaration was added to this file route.

### 2026-08-05 - B005 UID0003YS non-emitting source route

- Added the exact collection-growth rollback, `0x2b0`/`+0x258` nested lifetime, free/rethrow, zero data/pointer route, UID0000BK/UID0000BL ownership split, and no-standalone-source evidence.
- Historicalized command `000000021217`'s UID0003YS Empty Emitter Marker; retained command `000000021232` only as a dated report-time generated-absence receipt and command `000000021253` only as a dated report-time by-file validation receipt with generated refresh skipped. Current generated/manual authority requires direct primary-supervisor refresh and verification. No target CPP/H body or primary-supervisor coherent generated/tracker credit is claimed; this file's `88/91` metadata and all unrelated contents remain preserved.

### 2026-08-04 - B007 UID0003YT header-owned teardown route

- Preserved file metadata at `88/91`, `CANONICAL_OWNER:FILE`, the `NexusTK/ui/dialogs/` route, and all existing ranking-family content.
- Added the class-header source cause, exact storage-release behavior, small/large allocation handling, double-underscore runtime callee, nine-site lifetime context, `sub_45C2A0` EH-tail ownership, target blank-code policy, and supervisor-owned generated-marker correction boundary.

### 2026-08-04 - B005 UID0002KA reset-before-request source-route callback

- Preserved file metadata, the existing RankingDialog family inventory, and all later reward/scroll/vector work.
- Added the exact sole caller at `0x004594f7`, ignored residual `EAX` proof, `void ResetUserEntries()` contract, clear-without-free vector lowering, `m_localPlayerRank = -1` behavior, request interval, response-parser reload lifecycle, and paint consumer.
- Preserved the selected-user-index and raw pointer-field source forms as disproved historical interpretations while routing human source through `RankingDialog.cpp/.h` without duplicate file-level emission.

### 2026-08-04 - B007 C31 Gate2B-prestate correction

- Added the exact physical UID0002K6 postpad model to the file route: one existing unnamed, untyped, non-code five-byte data item spans `[0x0045c01b,0x0045c020)`, contains five CC bytes, and has blank comments and zero xrefs.
- Preserved the earlier non-emitting-alignment conclusion, corrected method endpoint, `RankingDialog.cpp/.h` placement, class/file ownership, metadata, and every unrelated ranking-family route; only the physical IDA item representation changed.

### 2026-08-04 - B007 UID0002K6 source-route callback

- Preserved file metadata at `88/91`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, every unrelated ranking entity, and all pollution exclusions.
- Added the corrected UID0002K6 endpoint, non-const vector-based source definition/declaration route, signed/no-lower-bound behavior, sole ten-row caller, five-byte postpad, and rejected raw-field/const/defensive alternatives.
- Recorded command20963's pre-callback CPP/H mismatch and the validator-owned command20975 correction, while leaving the single coherent post-Gate2/manual-coverage refresh in supervisor-owned C23 rather than editing generated output or changing source placement.

### 2026-08-02 - B009 UID0002K3 standard-`tm` source-route sync

- Preserved file metadata at `88/91`, file ownership, `NexusTK/ui/dialogs/`, all unrelated ranking-family work, and the newer reward-claim/vector source routes already present in this file.
- Reconciled the RankingCategoryRecord entry with its `93/95` class, `92/94` non-emitting aggregate, standard 36-byte `tm` members, by-value getter ABI, direct packed setter semantics, paint consumers, and class/child formal emission route.
- Historicalized the former custom `RankingDateTimeParts` and explicit out-parameter source hypotheses without deleting their evidentiary role. The accepted declaration uses `<time.h>` in the class header; this grouping page remains documentation-only and gains no duplicate formal C++.

### 2026-08-02 - B001 UID0004ZM source-route sync

- Preserved file `88/91`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, file ownership, all existing ranking-family entities, and every unrelated historical/pollution exclusion.
- Reclassified UID0004ZM from registered raw blank helper to source-ready private `RankingDialog::RequestRewardClaim()` with exact child-owned CPP, corrected the primary handler to `OnControlCommand(int,int)`, and documented one retained definition plus one compiler-inlined case-6 call.
- Reconciled the exact selected-record/null flow, six-byte request, seven-byte response, UI refresh, source placement, negative route evidence, rejected owners, and historical no-code correction without adding duplicate file-level source.

### 2026-07-31 - B009 UID0003WU reward-claim route sync

- Preserved file metadata at `88/91`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, the complete B007 UID0004YX route, catalog0379 target/helper/type history, and every unrelated source child and pollution exclusion.
- Added source placement for UID0003WU and the exact six-byte request/seven-byte response/UI-refresh contract through UID0004ZM, UID0003WU, and UID0004YX.
- Rejected only the copied reward-helper UID000420 identity. Validator command `000000020264` allocated UID0004ZM to the exact ranking helper path; UID000420 remains canonically assigned to MapPane and is not a RankingDialog child.

### 2026-07-31 - B007 UID0004YX source-route sync

- Updated UID0004YX from inherited-API-blocked blank child to `92/94` source-ready method with complete exact-child formal CPP.
- Added exact range/callers/signature correction, selected-record/state behavior, concrete child classes/resources, inherited API contracts, page-bound transition semantics, existing source route, rejected owner/file alternatives, and superseded historical rationale.
- Gate 2A repair restored UID000425 to the exact RankingDialog max-page child using literal UID text plus the canonical path so duplicate registry state cannot redirect the link to unrelated MapPane collision content. B009's UID0003WU reward-claim response/UI-refresh additions remain intact; active UID0004YX IDA evidence is rebound to current saved IDB `B7CC899D...58277`, while catalog0379 SHA `4B5F...A696A` remains dated history.
- The same duplicate-safe repair restores UID000422, UID000424, and UID000427 to their exact RankingDialog helper pages. Their literal UID text and canonical links deliberately avoid the unrelated MapPane entries that share those copied historical UIDs.
- Preserved file `88/91`, `NexusTK/ui/dialogs/`, every unrelated entity/source route, all prior accepted history, and broader output-pollution/fine-split caveats.

### 2026-07-31 - Supervisor catalog0379 IDA route sync

- Recorded the saved target/helper source-facing names, exact prototypes/comments, minimal incomplete collection type, protected no-change readback, and backup/postsave identities.
- Historicalized the former raw target/helper names and declarations without deleting them as binary provenance. No file score/path/grouping, generated source, manual coverage, or unrelated entity changed.

### 2026-07-13 - B004 UID0000Y0 Singleton-base source-route sync

- Preserved file `88/91`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, every ranking source child/body/score, UID0000YA, and all pollution exclusions.
- Replaced UID0000Y0's handwritten/generic clear-helper route with non-emitting `Singleton<RankingDialog>` base-destructor support; added RTTI `+0x26c`, EBO, constructor-state/EH-map ordering, four-store destruction lifetime, 17-xref storage route, comparator limits, and exhaustive no-standalone-source disposition.
- Historicalized the older custom IDA helper name. No file score, generated source body, helper declaration, explicit specialization, catch/guard, late-publication expression, or unrelated family disposition changed.

### 2026-07-12 - B001 UID0001ZJ exact-child route sync

- Preserved `88/91`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, all class/source routes, generated-pollution exclusions, and every executed X7/X9/ZK fact unchanged.
- Reclassified UID0001ZJ as a `92/94` non-emitting split index and added exact UID0000BP-routed children UID0004J3-UID0004J7 for completed range destruction, nested item-vector destruction, guarded range copy, item allocation, and failed entry-storage free.
- Source output remains ordinary UID0000BP declarations and UID0001ZF/UID0001ZH vector operations. No new file, helper body, metadata field, score, or path changed.

### 2026-07-12 - B005 UID0001ZK source-route sync

- Preserved `88/91`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, all ranking contents/pollution exclusions, every source body, and executed X7/X9 content unchanged.
- Added only the marker-covered UID0001ZK route through UID0000BP: `92/94` compiler/STL outer vector destruction generated by existing nested/outer vector members, with exact destructor/EH, layout, allocator, triplet-clear, and implicit-special-member context. No standalone helper or explicit destructor source was added.

### 2026-07-12 - B001 UID0003X9 source-route sync

- Preserved `88/91`, `CANONICAL_OWNER:FILE`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, all ranking contents/pollution exclusions, every source body, and executed B002 X7 layout/EH output unchanged.
- Added only the marker-only UID0003X9 route through UID0000BP/UID0001ZH: `92/94` compiler/STL item-vector copy construction, one `m_rewardEntries.push_back(entry);` source operation, natural entry alignment, complete generated rollback support, and expected removal of the target Empty Emitter Marker without a standalone helper body.

### 2026-07-12 - B005 UID0000Y5 split/class/reset route sync

- Metadata remains `88/91`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
- Added UID0000Y5 `90/93` non-emitting split index, exact source children UID0004J0/UID0004J1/UID0004J2, source-ready UID0000Y7 reset, and UID0000BO `89/92` class declaration/tail-field support.
- Preserved executed B003 Y6 formal block/`90/92`/owner factorization and changed only relative `Nested:-4`; preserved UID0000Y2 no-standalone marker, all Y3/Y4/Z9/ZA/ZB bodies/scores, ranking vtable/resource routes, generic-render pollution exclusions, and historical evidence.
- Generated expectation: one class shell with children, one each of the three new methods, one byte-preserved Y6, one Y7, no duplicate method definitions, no Y5 empty marker, and UID0000Y2 remaining the expected empty marker.

### 2026-07-12 - B003 UID0000Y6 DragToPosition route sync

- Changed to: documentation/source-route support only; file remains `88/91`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`.
- Summary/evidence: UID0000Y6 now emits exact `void RankingEventScrollPane::DragToPosition(int y, int x)` at `90/92` through UID0000BO, preserving exact range/padding, six callers, y/x fields, sentinel-controlled bounds, signed clamp/division math, no-change behavior, and factorized `RankingEventListPane::SetScrollPosition(0, old, new)` owner synchronization.
- Preserved: all generated-pollution exclusions, reward/category/dialog routes, file score/path/ownership, class declaration caveat, and B005-owned UID0000Y5/UID0000Y7/class split work.

### 2026-07-12 - B004 UID0001ZB GetPartRect route sync

- Changed to: documentation/source-route support only; file `88/91`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged. The RankingEventScrollPane contents and historical blocker text now identify UID0001ZB as a separately accepted source-ready method.
- Evidence: accepted B004 report SHA256 `1EE84348BCBB99F49649536529ED4DBCBF15E30FAACD46AED663DA084ABAA915` and evidence-time MCP database `bf5519ae` requests `62006-62019` preserve the exact target range/pads, caller/callee closure, source-facing signature, sentinel and untouched-output behavior, full orientation/part/disabled/drag geometry, accepted fields/types, and RankingEventScrollPane ownership through this file route.
- Preserved: all sibling method/raw-island dispositions, file score/path/ownership, whole-class declaration compile-support caveat, historical prior blocker context, original-name/final-build confidence caps, and rejected generic/FittingRoom/ScrollCollection/split alternatives.

### 2026-07-12 - B001 UID0003X8 source-quality sync

- Preserved `RankingDialog.cpp` routing, file metadata, all B002 reward-dialog content, child bodies, and scores. Replaced every current UID0003X8 `StringUtil` ownership assertion with the accepted `90/92`, owner `NONE`, non-reconstructable fixed-256 compiler/UCRT support disposition; UID0004IA remains the ranking-owned caller expression.

### 2026-07-12 - B001 UID0001ZF source-ready route closure

- Documentation/source-route update only; file metadata, projected path, and canonical file ownership remain unchanged.
- UID0001ZF now emits `RankingRewardEntry::ParseFromPacket` plus four accessors through UID0000BP at `91/92`. Its historical counted-string/no-caller decision is resolved; raw `GetItemCount` is inventoried as executable source, and the generated route retains existing UID000202/UID000204, UID0001ZG, UID0001ZH, UID0004I7-UID0004IE, and vector-helper dispositions unchanged.

### 2026-07-12 - B002 UID0001ZH packet-handler route closure

- Documentation/source-route update only; file metadata remains unchanged.
- Current MCP database `cfa0ae1a` and accepted EventHandler, Event payload, ranking accessor, Pane invalidation, and vector APIs resolve UID0001ZH's former packet-interface blocker. The file now routes source-emitting `RankingRewardInfoDialog::HandlePacketEvent(Event *event)` through UID0000BP and removes UID0001ZH from the current no-code inventory while preserving the historical B006 state.

### 2026-07-12 - B002 UID0001ZG exact reward-dialog route sync

- Changed to: documentation support only; `88/91`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: UID0001ZG is now a non-emitting split index, not an empty source method. UID0004I7, UID0004I9, UID0004IA, UID0004IB, and UID0004IC emit constructor/action/paint/private-helper bodies through UID0000BP; UID0004I8, UID0004ID, and UID0004IE remain compiler/EH/ABI non-emitting. Existing packet/vector/singleton/thunk dispositions and UID0003X8 exclusion are preserved; later UID0003X8 review resolves the excluded target as owner-`NONE` compiler/UCRT support.

### 2026-07-12 - B004 UID0000Y4 HitTestPart route sync

- Changed to: documentation support only; `COMPLETION`, `CONFIDENCE`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: [UID:0000Y4][0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart](by-memory/0x0045a400-0x0045a70b.RankingEventScrollPaneHitTestPart.md) now emits first-draft `RankingEventScrollPane::HitTestPart(int y, int x)` through [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md). Current MCP session `359c7886` preserves the exact boundary, vtable-only xref, no-callers result, y-first ABI, orientation/enable gate, six-way part classification, and horizontal `right - 38` no-code threshold.

### 2026-07-12 - B003 UID0001ZA OnPaint route sync

- Changed to: documentation support only; `COMPLETION`, `CONFIDENCE`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: UID0001ZA now emits first-draft `RankingEventScrollPane::OnPaint()` through [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md). Current MCP session `359c7886` preserves the exact boundary/vtable/no-caller facts, two clipped track passes, thumb pass, resource/frame mapping, accepted shared helper contracts, and target `89/91` score. UID0000BO declaration/enum/field support remains a separate generated compile-completeness requirement.

### 2026-07-09 - B004 UID0000Y2 no-standalone aggregate sync

- Changed to: documentation support only; `COMPLETION`, `CONFIDENCE`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: [UID:0000Y2][0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters](by-memory/0x004598b0-0x00459a59.RankingEventScrollPaneRawCtorAndSetters.md) now records the accepted B004 no-standalone proof at `88/91`. Current MCP session `supervisor_nexustk_20260709` confirmed the raw byte range, no function objects/xrefs/pointer-route bytes, successor boundary `0x00459a60`, vtable route, and repaired layout roles for `m_scrollSkinIndex`, `m_scrollStyle`, `m_scrollPosition`, `m_scrollRange`, and enabled/highlight/active flags. UID0000Y2 remains a deliberate generated empty marker; it does not block the RankingDialog file route.

### 2026-07-09 - B003 UID0000Y3 OnMouseEvent route sync

- Changed to: documentation support only; `COMPLETION`, `CONFIDENCE`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: [UID:0000Y3][0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent](by-memory/0x00459a60-0x00459ccd.RankingEventScrollPaneOnMouseEvent.md) now emits first-draft `RankingEventScrollPane::OnMouseEvent(const PaneMouseEvent& event)` through [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md). Accepted B003 evidence from MCP session `supervisor_nexustk_20260709` preserves the `sub_459A60` `0x26e` size, end-exclusive `0x00459cce`, vtable-only xref `0x00610a9c`, no direct callers, event-kind dispatch, boundary padding, and source-facing names. The method should no longer appear as a UID0000Y3 empty marker after validator/autogen refresh, while [UID:0000BO][RankingEventScrollPane](by-class/RankingEventScrollPane.md) class declaration support remains a separate compile-completeness requirement.

### 2026-07-03 - B005 UID000204 ItemAt route sync

- Changed to: documentation only; `COMPLETION`, `CONFIDENCE`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: [UID:000204][0x0045db60-0x0045db9e.RankingRewardEntryItemAt](by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md) now emits through [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) as `RankingRewardEntry::ItemAt(int index)`. Accepted B005 evidence preserves the no IDA function object, no ordinary xrefs, no pointer-pattern hits, unique body bytes, parser/paint layout proof, exact padding/constructor boundaries, and no-negative-index-check behavior. [UID:0000MZ] remains the file/source-route page, not the direct semantic owner.

### 2026-07-03 - B004 UID000202 constructor route sync

- Changed to: documentation only; `COMPLETION`, `CONFIDENCE`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: [UID:000202][0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit](by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md) is no longer a stale empty-marker/blocker for this route. It now emits source through [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) as `RankingRewardEntry::RankingRewardEntry()`, with accepted B004 evidence for no IDA function object, failed raw-start decompile, exact bytes/disassembly, no xrefs, no pointer-pattern hits, boundary padding, adjacent cleanup/parser split, and packet-handler inline temporary parity. [UID:0000MZ] remains the file/source-route page, not the direct semantic owner.

### 2026-06-30 - B006 narrowed empty-emitter callback implementation

- Before: `87/90`, with no direct [UID:0000MZ] source-quality closeout and older wording that could be misread as broad full-family empty-emitter cleanup.
- Changed to: `88/91`; `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CANONICAL_OWNER:FILE` remain unchanged.
- Summary/evidence: B006's accepted narrowed callback incorporated active MCP database `supervisor_resume_20260629` request ids `2004-2016`, adopted the accepted FittingRoom default-false pattern for [UID:0001Z9][0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect](by-memory/0x00459cd0-0x00459cd4.RankingEventScrollPaneHasActiveEffect.md), added source-level singleton output through [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md)/[UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md) while making [UID:00028U][0x0067a7e4-0x0067a7e8.g_pRankingDialog](by-memory/0x0067a7e4-0x0067a7e8.g_pRankingDialog.md)/[UID:00028V][0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog](by-memory/0x0067a7e8-0x0067a7ec.g_pRankingRewardInfoDialog.md) non-emitting storage support, added reward support declarations through [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md), and preserved formal no-code blockers for [UID:0002K9][0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry](by-memory/0x0045c1e0-0x0045c238.RankingCategoryRecordAppendUserEntry.md), [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md), and [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md). The old [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) executable-island report is historicalized as support/duplicate-avoidance rather than a direct file closeout; the rejected broad 36-row cleanup remains withdrawn.

### 2026-06-23 - B001 accepted RankingDialog source-quality implementation

- Before: `86/88`, with a strong ranking feature grouping but no exact pages for the `0x00459580-0x00459804` main-dialog helpers or the `0x0045c020/30/40/1b0/1d0` record setters.
- Changed to: `87/90`; `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` and `CANONICAL_OWNER:FILE` remain unchanged.
- Summary/evidence: current MCP session `80de0a67` reconfirmed the broad feature-module route, ranking opcode `0x7d` request/response family, raw/helper inventories, singleton/vtable evidence, helper child splits, packet sender/writer normalization, and preserved exclusions for WebBoardOld, ExchangeDialog helpers, popup/menu/dialog animation, shared GrafPort/render helpers, and shared [UID:0003X8][0x0045ef20-0x0045ef50.WideFormatWrapper256](by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md).

### 2026-06-20 - B004 WebBoardDialogOld URL escape exclusion sync

- Changed to: documentation only; scores remain `86/88`.
- Summary/evidence: B004 accepted [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md) as file-local `EscapeOldWebBoardUrl` under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), preserving RankingDialog as a rejected generated-output owner for old WebBoard helper code.

### 2026-06-21 - B008 WebBoardDialogOld class-route exclusion sync

- Changed to: documentation only; scores remain `86/88`.
- Summary/evidence: B008 accepted [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) as the old fixed-art WebBoard variant under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), not a RankingDialog class or helper family.

### 2026-06-20 - B001 K8 implementation sync

- Changed to: documentation only; scores remain `86/88`.
- Summary/evidence: [UID:0002K8][0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime](by-memory/0x0045c100-0x0045c1a9.RankingCategoryRecordSetEndTimeFromPackedDateTime.md) now has the accepted corrected endpoint, raw PE hash/offset evidence, parser callers `0x0045c4b3` and `0x0045c787`, no-callee/no-pointer-route evidence, and first-draft C++. This removes the prior K8 empty-marker blocker from the RankingCategoryRecord route through `RankingDialog.cpp`.

### 2026-06-17 - B002 ExchangeDialog generated-pollution sync

- Changed to: documentation only; scores remain `86/88`.
- Summary/evidence: B002's [UID:00014O][0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper](by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md) source-quality pass confirmed `0x004add40` is ExchangeDialog cancel-alert helper code and the sibling `0x004ade60` is the ready-alert helper. The RankingDialog file page now names those generated-output outliers explicitly so they are not migrated into `RankingDialog.cpp`.

### 2026-06-16 - B001 ranking reward/vector source-quality execution

- Changed to: documentation only; scores remain `86/88`.
- Summary/evidence: direct reward helper ownership now routes through [UID:0000BP][RankingRewardInfoDialog](by-class/RankingRewardInfoDialog.md) after the class support refresh. [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md) is a non-emitting split index, and UID0003X8 remains excluded from ranking ownership; later dedicated review classifies it as non-emitting owner-`NONE` compiler/UCRT support.

### 2026-06-16 - A002 Goal 2 file evidence refresh

- Before: `85/86`, with good parent-gate evidence but stale support scores and no current A002 live check.
- Changed to: `86/88`; `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"` remain unchanged.
- Summary/evidence: live IDA reconfirmed RankingDialog method boundaries/names, the dispatcher constructor edge, vtable-only packet handler, all 17 singleton refs, opcode `0x7d` packet dispatch, raw event-scroll helper no-function/no-xref status, and clean padding before the raw scroll constructor. Support pages now include [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md) at `85/88`, [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md) at `87/91`, [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) at `85/90`, and [UID:0000S2][g_pRankingDialog](by-global/g_pRankingDialog.md) at `85/90`. Final C++ stays blank because final field/helper names and generated-output pollution cleanup remain unresolved.

### 2026-06-11 - A002 vtable-family consistency refresh

- Before: the assignment-gate support list still described [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) as `84/90`.
- Changed to: updated that support reference to `85/90` after the vtable-family page passed its assigned gate review.
- Summary/evidence: [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md) now records a live IDA recheck, the file-level parent decision, and the child `85/90` / direct parent `85/86` gate.

### 2026-06-07 - Batch 095 parent-gate refresh

- Before: score was `82/86`; the page was strong but below the corrected `85/85` parent-side gate for assigning class children.
- Changed to: score is `85/86`.
- Summary/evidence: exact ranking read-only data [UID:0002ON][0x00610980-0x00610e38.RankingDialogReadOnlyData](by-memory/0x00610980-0x00610e38.RankingDialogReadOnlyData.md), vtable-family page [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md), executable ranking aggregate [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md), and exact method children now give this file page enough documented inventory, boundary, resource, vtable, and pollution-exclusion evidence to serve as the direct parent for ranking class pages that independently clear `85/85`. Remaining original filename/split caveats keep confidence unchanged.

### 2026-05-30 - Grading update

- Before: the file-placement page had detailed ranking UI grouping, packet/resource model, boundary notes, migration notes, and owner-pollution exclusions but remained unevaluated by the completion/confidence header.
- Changed to: score is now `82/86`, reflecting strong evidence that the ranking UI belongs in one `RankingDialog.cpp`-style feature module while keeping the final original filename and recovered-output-cleanliness caveats.
- Summary/evidence: IDA-backed pages identify the main dialog, event scroll/list panes, category collection/record, reward-info dialog, user-list pane, opcode `0x7d` handlers, vtable families, globals, resources, and non-ranking helper pollution.

### 2026-05-27 - Expanded RankingCategoryCollection placement evidence

- Before: `RankingCategoryCollection` was listed as `0x0045c260-0x0045d4f8` with no exact memory-page references and no constructor/parser caveat.
- Changed to: expanded the proposed contents row through the storage helper tail, linked exact memory docs for the parser/helper cluster and vector-storage helpers, and added the constructor/parser caveat.
- Summary/evidence: IDA confirms parser/accessor/helper starts from `0x0045c260` through `0x0045d740`; `0x00459210` dispatches ranking opcode subcommands to the parser methods; `0x0045c260` disassembly lacks the generated selected-id initialization.

### 2026-05-27 - Expanded RankingRewardInfoDialog helper ownership

- Before: `RankingRewardInfoDialog` was listed only as `0x0045dba0-0x0045f12c`, which hid the preceding parser/accessor island and trailing range/allocation helpers.
- Changed to: expanded the proposed contents row to `0x0045d7e0-0x0045f33a`, linked exact reward parser, core, packet-handler, vector-storage, destroy, and range-allocation memory docs.
- Summary/evidence: IDA confirms the reward-info packet handler at `0x0045ddd0`, parser at `0x0045d7e0`, vector helpers through `0x0045f33a`, and nested 560-byte reward entry / 520-byte item row ownership used by reward drawing.
