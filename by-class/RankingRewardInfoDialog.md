*** UID:0000BP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000MZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../core/BlackHole.h"

typedef EPFTileContext FrameDrawRecord;

class Event;

struct RankingRewardItem
{
    wchar_t name[256];
    int quantity;
    unsigned short iconId;
    unsigned char paletteIndex;
    unsigned char reserved_207;
};

typedef std::vector<RankingRewardItem> RankingRewardItemVector;

struct RankingRewardEntry
{
    RankingRewardEntry();
    int ParseFromPacket(const unsigned char *packet);

    wchar_t rankStartText[8];
    wchar_t rankEndText[8];
    wchar_t symbolText[256];
    char symbolFrameIndex;
    unsigned char symbolAttribute;
    RankingRewardItemVector items;

    wchar_t *GetRankStartText();
    wchar_t *GetRankEndText();
    int GetItemCount() const;
    wchar_t *GetSymbolText();
    RankingRewardItem *ItemAt(int index);
};

typedef std::vector<RankingRewardEntry> RankingRewardEntryVector;

class RankingRewardInfoDialog : public DialogPane
{
public:
    RankingRewardInfoDialog();

    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();
    virtual void OnDialogAction(int actionId, int actionParam);

private:
    void BuildCloseButtonBounds(short layoutSelector, RectBounds *outBounds) const;
    void SendRewardInfoRequest();

    RankingRewardEntryVector m_rewardEntries;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# RankingRewardInfoDialog

## Status

- Likely source file: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- Address range: [UID:0000XZ][0x00458610-0x0045f9f5.RankingDialog](by-memory/0x00458610-0x0045f9f5.RankingDialog.md)
- Exact class core: [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md)
- Autogen parent: [UID:0000MZ][RankingDialog](by-file/RankingDialog.md).
- Confidence: high for dialog purpose, exact class declaration, constructor/action/paint/private-helper bodies, packet handler, `std::vector` reward-entry/item layout, direct reward helper ownership, and compiler-artifact dispositions.

## Class Purpose

`RankingRewardInfoDialog` is the modal reward-detail dialog opened from the main ranking window. It requests reward info for the selected category, parses reward rows, draws rank/reward/item reward columns, and tracks its own active singleton.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `RankingRewardInfoDialog` | [UID:0004I7][0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor](by-memory/0x0045dba0-0x0045dd56.RankingRewardInfoDialogConstructor.md) | Source-ready constructor; stores the singleton, adds image button `14`, creates/shows the dialog, sends the request, and slides open. |
| `OnDialogAction` | [UID:0004I9][0x0045dda0-0x0045ddc2.RankingRewardInfoDialogOnDialogAction](by-memory/0x0045dda0-0x0045ddc2.RankingRewardInfoDialogOnDialogAction.md) | Source-ready action-zero close and deferred-delete override. |
| `HandlePacketEvent` | [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md) | Source-ready secondary `EventHandler` packet-family override for opcode `0x7d`, subcommand `5`; validates the selected category, parses and appends reward entries, invalidates the dialog bounds, and returns the exact handled state. |
| `OnPaint` | [UID:0004IA][0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint](by-memory/0x0045df90-0x0045ea13.RankingRewardInfoDialogOnPaint.md) | Source-ready full web-board frame, category/rank/symbol, and reward-item paint override. |
| `BuildCloseButtonBounds` | [UID:0004IB][0x0045ea20-0x0045ea5e.RankingRewardInfoDialogBuildCloseButtonBoundsRaw](by-memory/0x0045ea20-0x0045ea5e.RankingRewardInfoDialogBuildCloseButtonBoundsRaw.md) | Retained/inlined private source helper for invalid or `(279,468,63,24)` close bounds. |
| `SendRewardInfoRequest` | [UID:0004IC][0x0045ea60-0x0045ead9.RankingRewardInfoDialogSendRewardInfoRequestRaw](by-memory/0x0045ea60-0x0045ead9.RankingRewardInfoDialogSendRewardInfoRequestRaw.md) | Retained/inlined private source helper for opcode `0x7d`, subcommand `5`, selected-category request. |
| `RankingRewardEntry` default constructor | [UID:000202][0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit](by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md) | Source-ready out-of-line constructor that zeroes the nested item-vector triplet and sets `symbolFrameIndex` to `-1`; no-function/no-xref evidence caps confidence. |
| `RankingRewardEntry::ItemAt` | [UID:000204][0x0045db60-0x0045db9e.RankingRewardEntryItemAt](by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md) | Source-ready private/support accessor that returns a nested reward item by index with the original no-negative-index-check behavior; no-function/no-xref evidence caps public API confidence. |
| `RankingRewardEntry::ParseFromPacket` / accessors | [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) | Source-ready parser plus `GetRankStartText`, `GetRankEndText`, raw `GetItemCount`, and `GetSymbolText`; preserves CP_ACP counted strings, signed item count, consumed-byte return, `std::vector<RankingRewardItem>` append/count semantics, exact pads, and no-route/original-name confidence caps. |
| `RewardVectorStorageHelpers` | [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md) | Non-emitting split index for reward vector helpers and the shared formatter child. |
| `ConstructorUnwindCleanup` | [UID:0004I8][0x0045dd60-0x0045dd9a.RankingRewardInfoDialogConstructorUnwindCleanup](by-memory/0x0045dd60-0x0045dd9a.RankingRewardInfoDialogConstructorUnwindCleanup.md) | Non-emitting compiler cleanup for vector, singleton, and base rollback. |
| `ClearSingletonHelper` | [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md) | Constructor-unwind helper that clears [UID:0000S3][g_pRankingRewardInfoDialog](by-global/g_pRankingRewardInfoDialog.md). |
| `RangeDestroyCleanupFunclet` | [UID:0004ID][0x0045eff0-0x0045f018.RankingRewardEntryRangeDestroyCleanupFunclet](by-memory/0x0045eff0-0x0045f018.RankingRewardEntryRangeDestroyCleanupFunclet.md) | Non-emitting EH cleanup for nested item vectors across partial entry ranges. |
| `RewardContainerDestroy` | [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md) | `92/94` source-declared/generated-binary outer vector destruction covered by the existing `items` and `m_rewardEntries` declarations; no standalone helper or explicit entry-destructor body. |
| `AdjustorThunks` | [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md) | Compiler-generated destructor adjustor thunks for the inherited secondary/tertiary views; exact half-open body ends at `0x0045f0be`. |
| `ScalarDeletingDestructor` | [UID:0004IE][0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor](by-memory/0x0045f0c0-0x0045f12c.RankingRewardInfoDialogScalarDeletingDestructor.md) | Non-emitting compiler wrapper for vector/singleton/base teardown and optional free. |
| `RewardVectorRangeAllocationHelpers` | [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md) | `92/94` non-emitting split index for five exact source-declared/generated-binary children: UID0004J3 entry-range destroy, UID0004J4 nested item-vector destroy/free, UID0004J5 guarded entry-range copy construction, UID0004J6 item storage allocation, and UID0004J7 failed entry-storage free. |

## Data Notes

- `g_pRankingRewardInfoDialog` is `dword_67A7E8` at `0x0067a7e8`.
- Reward entries are 560-byte records best documented as `RankingRewardEntry`: `rankStartText[8]` at `+0x00`, `rankEndText[8]` at `+0x10`, `symbolText[256]` at `+0x20`, `symbolFrameIndex` at `+0x220`, packet-backed `symbolAttribute` at `+0x221`, implicit natural alignment padding at `+0x222..+0x223`, and `std::vector<RankingRewardItem> items` at `+0x224` (generated begin/end/capacity at `+0x224/+0x228/+0x22c`). The two padding bytes are deliberately absent from the source declaration.
- Item reward rows are 520-byte records best documented as `RankingRewardItem`: `name[256]` at `+0x000`, `quantity` at `+0x200`, `iconId` at `+0x204`, `paletteIndex` at `+0x206`, and one reserved/alignment byte at `+0x207`.
- Item reward rows draw item icons through `g_pItemObjImageLib` and labels formatted as `%s(%d)`.
- IDA confirms primary, secondary, and tertiary vtables at `0x00610bc4`, `0x00610c24`, and `0x00610c54`.
- The complete object size is `0x278`; inherited `DialogPane` state ends before the derived `std::vector<RankingRewardEntry> m_rewardEntries` tail at `+0x26c/+0x270/+0x274`.
- Use the exact `by-memory` pages above for reconstruction of the packet-handler, parser, and storage helper bodies.
- Exact reward helper children split from [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md): [UID:0003X6][0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth](by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md), [UID:0003X7][0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth](by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md), and [UID:0003X9][0x0045ef50-0x0045efd0.RankingRewardItemVectorClone](by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md) route here. [UID:0003X8][0x0045ef20-0x0045ef50.WideFormatWrapper256](by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md) is independently reviewed non-emitting MSVC/UCRT fixed-256 support with owner `NONE`, not this class.
- Exact reward range/allocation children split from UID0001ZJ also route here: [UID:0004J3][0x0045f130-0x0045f15b.RankingRewardEntryRangeDestroy](by-memory/0x0045f130-0x0045f15b.RankingRewardEntryRangeDestroy.md), [UID:0004J4][0x0045f160-0x0045f1c6.RankingRewardItemVectorDestroy](by-memory/0x0045f160-0x0045f1c6.RankingRewardItemVectorDestroy.md), [UID:0004J5][0x0045f1d0-0x0045f285.RankingRewardEntryRangeCopyConstruct](by-memory/0x0045f1d0-0x0045f285.RankingRewardEntryRangeCopyConstruct.md), [UID:0004J6][0x0045f290-0x0045f2f3.RankingRewardItemVectorAllocateStorage](by-memory/0x0045f290-0x0045f2f3.RankingRewardItemVectorAllocateStorage.md), and [UID:0004J7][0x0045f300-0x0045f33a.RankingRewardEntryVectorFreeStorage](by-memory/0x0045f300-0x0045f33a.RankingRewardEntryVectorFreeStorage.md). Each child carries one formal no-duplicate marker; the UID0001ZJ parent emits nothing.

## Source-Quality Decisions

- `RankingRewardEntry` uses text buffers for the rank bounds. Numeric `minRank`/`maxRank` field names were rejected because the parser converts length-prefixed multibyte packet strings into wide strings and the accessors return `wchar_t *` buffers. Generic `titleText`/`rewardText` names were also rejected because packet-handler and paint context tie these buffers to rank-range and symbol display.
- `symbolFrameIndex` at `+0x220` is a real packet/default field, not padding: the initializer writes `0xff`, and the parser overwrites it from packet data. The next byte is best kept as conservative `symbolAttribute`; `symbolPaletteIndex` or hard `flags` wording overclaims the current evidence, while padding is impossible because the parser explicitly writes the byte.
- `RankingRewardItem` keeps `quantity`, `iconId`, and `paletteIndex` as the best source-facing names. A generic `rewardId` was rejected for the `+0x200` dword because it follows the item name and is used in reward-label formatting as a count. A 32-bit `iconId` was rejected because the parser writes the icon field through the 16-bit slot at `+0x204`.
- The byte at item offset `+0x207` is accounted for by the `0x208` stride but remains reserved/implicit padding until a reader gives it source semantics. It should not block the 85/85 documentation gate or force an artificial field in final C++.
- [UID:000202][0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit](by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md) is now source-ready as `RankingRewardEntry::RankingRewardEntry()`: current B004 MCP evidence proves no IDA function object, failed raw-start decompile, exact raw bytes/disassembly, no incoming xrefs, no pointer-pattern hits, six-byte prepad, fourteen-byte postpad, adjacent cleanup thunk/parser boundary, and packet-handler inline temporary parity. The constructor writes only `itemsBegin/itemsEnd/itemsCapacity = 0` and `symbolFrameIndex = -1`; it does not initialize rank/symbol text, parser-backed `symbolAttribute`, or reserved alignment bytes.
- [UID:000204][0x0045db60-0x0045db9e.RankingRewardEntryItemAt](by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md) is now source-ready as `RankingRewardEntry::ItemAt(int index)`: current B005 MCP session `b010_00032w_20260703` proves no IDA function object, exact raw disassembly/arithmetic, no ordinary incoming xrefs, no start/interior/end pointer-pattern hits, unique body bytes, `0xcc` alignment windows, separate constructor successor, parser writes to the same nested item vector, and paint's inline traversal of the same `0x208` rows. The method intentionally has no `index < 0` guard; route-negative evidence caps public API confidence rather than blocking private/support source output.
- Reward vector helpers are source-placed with this dialog because their strides, nested deep-copy behavior, parser/packet-handler callers, and destructor paths encode `RankingRewardEntry` and `RankingRewardItem` ownership. The class now emits the `std::vector` source abstractions; exact helper pages retain their accepted source-declared/generated-binary or non-emitting dispositions rather than duplicating template mechanics by hand.
- [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) is source-ready at `91/92` as one same-type group. Its modeled parser is `0x0045d7e0-0x0045db06`; text getters are `0x0045db10-0x0045db13`, `0x0045db20-0x0045db24`, and `0x0045db50-0x0045db54`; raw `0x0045db30-0x0045db4e` is `GetItemCount() const`, not padding. The sole caller is source-emitting UID0001ZH. Zero accessor xrefs and pointer routes cap original spelling/publicness but do not block these ordinary source methods.
- UID0001ZF parser source deliberately keeps a raw packet pointer plus returned byte count, direct `CP_ACP` conversion, signed-byte item count, non-value-initialized `RankingRewardItem`, no packet bounds checks, and `items.push_back(item)`. PacketReader, UTF-8, unsigned-count, zero-fill, and defensive-bound rewrites were rejected because they change or invent behavior.
- [UID:0003X6][0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth](by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md) is now `92/93` source-declared/generated-binary support for that exact `items.push_back(item)` statement. Evidence-session `bf5519ae` proves its sole parser call, `0x208` trivial non-value-initialized row, vector triplet, maximum/growth, aligned allocation/header, relocation/publication, checked old-storage free, and no-local-EH disposition. Its formal marker points to UID0001ZF; the complete declarations and parser source on this page remain unchanged, and no standalone helper is emitted.
- [UID:0003X7][0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth](by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md) is now `93/94` source-declared/generated-binary support for UID0001ZH `m_rewardEntries.push_back(entry)`. Evidence-session `supervisor_20260712` proves its sole full-capacity caller, `0x230` stride, fixed-member copy through `+0x221`, omission of `+0x222..+0x223`, nested `items` deep copy, safe half-growth/aligned allocation, append and generic construction routes, old destruction/free, publication/return, local/helper EH guards, and strong exception guarantee. The formal marker points to UID0001ZH; no standalone growth helper is emitted.
- UID0003X7's repeated copy omission resolves the source declaration: `+0x222..+0x223` are implicit padding required to align `RankingRewardItemVector items` at `+0x224`, not an explicit `reserved_222[2]` member. Removing that false member preserves `sizeof(RankingRewardEntry) == 0x230` while making implicit memberwise copy construction match the binary.
- [UID:0003X9][0x0045ef50-0x0045efd0.RankingRewardItemVectorClone](by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md) is `92/94` source-declared/generated-binary `std::vector<RankingRewardItem>` copy-constructor support, not a source-authored clone helper. Its four compiler call sites are UID0001ZH's in-capacity append, UID0003X7's inserted-entry and end-relocation copies, and UID0001ZJ's entry-range copy. It zeroes the destination triplet, preserves empty vectors without allocation, allocates exact `0x208`-row count through UID0001ZJ, memmoves the complete trivial occupied span, and publishes end after copy. Outer X7/range guards advance only after success, so UID0004ID destroys completed disjoint `0x230` entry ranges exactly once and leaves the old vector unchanged on normal exceptions. Its formal marker is covered by the same literal UID0001ZH `m_rewardEntries.push_back(entry)` source; no standalone clone body or explicit entry padding field is emitted.
- [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md) is `92/94` source-declared/generated-binary `std::vector<RankingRewardEntry>` destruction. Its normal scalar-wrapper route passes this dialog's `m_rewardEntries` at `+0x26c`; constructor rollback reaches the same helper through raw call `0x0045dd83` and EH jump `0x005fa37f`. It walks live `0x230` entries, destroys each `items` member at `+0x224`, frees outer capacity storage with the MSVC large-allocation header check, and clears the triplet. The existing typed members are behaviorally complete: compiler-generated `RankingRewardEntry` destruction destroys `items`, and inherited virtual `DialogPane` destruction makes the implicit derived dialog destructor virtual. Explicit entry/dialog destructor bodies, raw vector fields, custom allocator source, and a standalone destroy helper are rejected.
- UID0001ZJ is now a `92/94` non-emitting split index rather than an empty source emitter. Its exact children preserve every specialization separately: UID0004J3 walks completed `0x230` entries; UID0004J4 frees a `0x208`-stride item-vector capacity and clears its triplet; UID0004J5 copies fixed members through `+0x221`, skips natural `+0x222..+0x223` alignment, deep-copies `items +0x224`, and maintains a completed-range guard; UID0004J6 handles zero/exact-small/32-byte-aligned large item allocation and oversized-count byte saturation; UID0004J7 frees failed new entry storage after completed entries are destroyed. The existing declarations, UID0001ZF `items.push_back(item)`, UID0001ZH `m_rewardEntries.push_back(entry)`, and implicit lifetime regenerate all five; no helper declarations or bodies are added here.
- [UID:0003X8][0x0045ef20-0x0045ef50.WideFormatWrapper256](by-memory/0x0045ef20-0x0045ef50.WideFormatWrapper256.md) is deliberately excluded from this class despite physical adjacency. Its ranking paint, screenshot JPG/BMP/PNG, and user-list source-message callers each pass caller-local 256-wide arrays; the exact fixed `0x100` local-options/secure-backend body and UCRT array-overload shape make it compiler/header support, not reward-dialog or `StringUtil` source.
- 2026-06-23 B001 current MCP session `80de0a67` reconfirms decompilation of `0x0045ddd0`: it accepts opcode `0x7d`, subcommand `5`, validates the selected category id through `g_pRankingDialog + 0x26c`, parses reward entries through [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md), appends/deep-copies nested vectors, cleans temporary item vectors, and invalidates the reward dialog.
- Request helper wording is normalized to [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md), [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Historical raw sender labels are search aliases only.
- Formal C++ now emits `RankingRewardItem`, `RankingRewardItemVector`, `RankingRewardEntry`, `RankingRewardEntryVector`, and the complete `RankingRewardInfoDialog : public DialogPane` declaration. `FrameDrawRecord` is an alias/layout view of the same 40-byte `EPFTileContext` consumed by accepted ResourceLayout/GrafPort helpers. `RankingRewardEntry::ParseFromPacket(const unsigned char *packet)`, all four accessor declarations, and `RankingRewardEntry::ItemAt(int index)` expose the accepted source bodies; `virtual bool HandlePacketEvent(Event *event)` uses the accepted EventHandler packet-family signature. The `[[CHILDREN]]` marker remains after all declarations so exact source bodies emit at file scope. UID0003X8 remains outside reward-dialog source and is now reviewed non-emitting owner-`NONE` compiler/UCRT support.
- B006 current MCP request id `2016` reconfirmed the support declarations: `rankStartText[8]`, `rankEndText[8]`, `symbolText[256]`, packet-backed bytes at `+0x220/+0x221`, two alignment bytes at `+0x222..+0x223`, and the nested item-vector triplet at `+0x224/+0x228/+0x22c`. `RankingRewardItem` remains a `0x208` row: `name[256]`, `quantity`, `iconId`, `paletteIndex`, and a reserved byte at `+0x207`.

## Score Rationale

- Completion is `91` because the class now has source-quality record/vector declarations, constructor/parser/four-accessor/item-index/action/packet/paint/private-helper declarations and bodies, exact compiler-artifact dispositions, and complete packet-handler dependency closure.
- Confidence is `93` because current MCP packet flow, EventHandler slot conventions, parser/accessor and vector layouts, paint loop, nested destructor/deep-copy behavior, normalized packet dependencies, and shared formatter exclusion agree. Remaining uncertainty is limited to original parser/accessor spellings and visibility, packet constant names, no-route accessors, and field polish such as the exact display meaning of `symbolAttribute`.

## Cross-References

- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000BM][RankingDialog](by-class/RankingDialog.md)
- [UID:0000BK][RankingCategoryCollection](by-class/RankingCategoryCollection.md)
- [UID:0001ZG][0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore](by-memory/0x0045dba0-0x0045f12c.RankingRewardInfoDialogCore.md)
- [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md)
- [UID:0001ZH][0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler](by-memory/0x0045ddd0-0x0045df8c.RankingRewardInfoPacketHandler.md)
- [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md)
- [UID:0003X6][0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth](by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md)
- [UID:0003X7][0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth](by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md)
- [UID:0003X9][0x0045ef50-0x0045efd0.RankingRewardItemVectorClone](by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md)
- [UID:0001ZK][0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy](by-memory/0x0045f020-0x0045f0a7.RankingRewardEntryVectorDestroy.md)
- [UID:0001ZJ][0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers](by-memory/0x0045f130-0x0045f33a.RankingRewardVectorRangeAllocationHelpers.md)
- [UID:0004J3][0x0045f130-0x0045f15b.RankingRewardEntryRangeDestroy](by-memory/0x0045f130-0x0045f15b.RankingRewardEntryRangeDestroy.md)
- [UID:0004J4][0x0045f160-0x0045f1c6.RankingRewardItemVectorDestroy](by-memory/0x0045f160-0x0045f1c6.RankingRewardItemVectorDestroy.md)
- [UID:0004J5][0x0045f1d0-0x0045f285.RankingRewardEntryRangeCopyConstruct](by-memory/0x0045f1d0-0x0045f285.RankingRewardEntryRangeCopyConstruct.md)
- [UID:0004J6][0x0045f290-0x0045f2f3.RankingRewardItemVectorAllocateStorage](by-memory/0x0045f290-0x0045f2f3.RankingRewardItemVectorAllocateStorage.md)
- [UID:0004J7][0x0045f300-0x0045f33a.RankingRewardEntryVectorFreeStorage](by-memory/0x0045f300-0x0045f33a.RankingRewardEntryVectorFreeStorage.md)
- [UID:0001YJ][RankingDialogVtableFamily](by-type/by-vtable/RankingDialogVtableFamily.md)
- [UID:0000YA][0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper](by-memory/0x0045efe0-0x0045efeb.RankingRewardInfoDialogClearSingletonHelper.md)
- [UID:0000YB][0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks](by-memory/0x0045f0a8-0x0045f0bd.RankingRewardInfoDialogAdjustorThunks.md)
- [UID:0001RK][ranking-ui-resources](by-resource/ranking-ui-resources.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md)

## Changes

### 2026-07-12 - B001 UID0001ZJ exact-child ownership sync

- Preserved `91/93`, owner/emitter UID0000MZ, the complete class/type/method declarations, every source body, natural `+0x222..+0x223` alignment, `[[CHILDREN]]`, and all executed X7/X9/ZK content unchanged.
- Reclassified UID0001ZJ as a `92/94` non-emitting split index and added its five real children UID0004J3-UID0004J7 with exact range-destroy, nested-destroy, guarded-copy, item-allocation, and failed-storage-free source dispositions.
- Added only compiler/STL covered-by relationships. No class member, method, destructor, allocator helper, formal C++ line, metadata field, or score changed.

### 2026-07-12 - B005 UID0001ZK implicit-destruction relation sync

- Preserved `91/93`, owner/emitter UID0000MZ, the complete formal class/type block, natural implicit `+0x222..+0x223` alignment, `[[CHILDREN]]`, every source body, and all executed X7/X9 content unchanged.
- Added only UID0001ZK's `92/94` compiler/STL destruction relation: exact three destructor/EH xrefs, dialog `m_rewardEntries +0x26c`, `0x230` entry walk, nested `items +0x224` teardown, checked capacity free, triplet clearing, implicit-special-member source cause, and no-duplicate marker. No explicit destructor declaration/body or standalone helper API was added.

### 2026-07-12 - B001 UID0003X9 copy-constructor relation sync

- Preserved `91/93`, owner/emitter UID0000MZ, the complete formal class/type block, natural implicit `+0x222..+0x223` alignment, `[[CHILDREN]]`, every source body, and all executed B002 X7 content unchanged.
- Added only UID0003X9's `92/94` compiler/STL copy-constructor relation: four call sites, exact-size `0x208` allocation/trivial copy, post-copy publication, complete outer guard behavior, and the existing UID0001ZH `m_rewardEntries.push_back(entry)` covered-by source. No standalone helper API or body was added.

### 2026-07-12 - B002 UID0003X7 class-layout and source-disposition sync

- Preserved `91/93`, owner/emitter UID0000MZ, every accepted type/method/class declaration, `[[CHILDREN]]` placement, all source bodies, and all unrelated class evidence.
- Applied the accepted complete formal block with only `reserved_222[2]` removed. Natural four-byte alignment retains implicit `+0x222..+0x223`, `items +0x224`, and `sizeof(RankingRewardEntry) == 0x230`.
- Added UID0003X7's `93/94` covered-by relation to UID0001ZH `m_rewardEntries.push_back(entry)`, exact memberwise/deep-copy shape, growth/allocation, construction/commit, and complete EH/strong-guarantee evidence. No standalone helper body or new API was added.

### 2026-07-12 - B002 UID0003X6 source-disposition sync

- Preserved the complete formal `RankingRewardItem`, vector aliases, `RankingRewardEntry`, parser/accessor declarations, dialog declaration, score, owner, and emitter unchanged.
- Added only the target-specific accepted relation: UID0003X6 is `92/93` compiler/STL full-capacity support covered by UID0001ZF `items.push_back(item)`, with no duplicate growth-helper source body.

- 2026-07-12 B001 UID0003X8 source-quality sync:
  - Preserved all class metadata, declarations, reward-child ownership, parser/accessor content, and score. Replaced every current `StringUtil` route for UID0003X8 with its accepted `90/92`, owner `NONE`, non-reconstructable compiler/UCRT fixed-256 support disposition. UID0004IA remains the class-owned caller and carries the caller-local secure array-overload expression.

### 2026-07-12 - B001 UID0001ZF parser/accessor declaration closure

- Before: `91/93` with accepted post-ZG/post-ZH vectors, class declaration, parser declaration, packet-handler declaration, and exact children, but no declarations for UID0001ZF's four out-of-line accessors.
- Changed to: score/owner/emitter and every B002 declaration/body unchanged; added only `GetRankStartText`, `GetRankEndText`, `GetItemCount() const`, and `GetSymbolText` declarations to `RankingRewardEntry` and expanded UID0001ZF source-quality notes.
- Summary/evidence: accepted UID0001ZF research proves parser `0x0045d7e0-0x0045db06`, three modeled text getters, raw reciprocal-division item count `0x0045db30-0x0045db4e`, exact pads, zero accessor xrefs/pointer routes, signed counted-string protocol, consumed-byte return, `std::vector<RankingRewardItem>` source shape, and the source-emitting UID0001ZH sole caller. No UID0001ZH, UID0001ZG, or UID0004I7-UID0004IE content changed.

### 2026-07-12 - B002 Gate 1 packet-interface closure

- Before: `90/92`; the class emitted its vector members and five core source bodies but retained stale wording that UID0001ZH lacked packet-listener, selected-category, vector, and invalidation APIs.
- Changed to: `91/93`; added `class Event`, `RankingRewardEntry::ParseFromPacket(const unsigned char *packet)`, and `virtual bool HandlePacketEvent(Event *event)` declarations. UID0001ZH now emits the accepted handler body through this class.
- Summary/evidence: current MCP session `cfa0ae1a` confirms the handler is secondary EventHandler slot `+0x10`, reads `Event::packet` at `+0x0c`, uses already-emitted ranking accessors and `m_rewardEntries`, and calls primary Pane slot `+0x20` with `&m_bounds`. This removes the only source-authored no-code child inside UID0001ZG; compiler/EH/ABI children remain non-emitting.

### 2026-07-12 - B002 UID0001ZG class/vector and source-body support

- Before: `87/91`; formal C++ exposed raw item-vector pointers and only support structs, while the full dialog declaration and five source bodies were withheld.
- Changed to: `90/92`; replaced raw triplets with `std::vector` aliases, added the complete `RankingRewardInfoDialog : public DialogPane` declaration and `m_rewardEntries`, and linked UID0004I7-UID0004IE with their source/compiler dispositions.
- Summary/evidence: current MCP confirms object size `0x278`, derived vector tail `+0x26c`, nested vector `+0x224`, ImageButton `(imageId,bounds)` construction, full paint dependencies, private retained-helper inline parity, vtable routes, and compiler cleanup/wrapper behavior. Constructor, OnDialogAction, OnPaint, BuildCloseButtonBounds, and SendRewardInfoRequest now emit from exact children; only proven compiler/EH/ABI children remain non-emitting.

### 2026-07-03 - B005 accepted RankingRewardEntry::ItemAt support sync

- Before: formal support declarations had `RankingRewardEntry` fields and the default-constructor declaration, but no item accessor declaration for [UID:000204][0x0045db60-0x0045db9e.RankingRewardEntryItemAt](by-memory/0x0045db60-0x0045db9e.RankingRewardEntryItemAt.md).
- Changed to: added `RankingRewardItem *ItemAt(int index);` to the emitted support struct and recorded UID000204 as a source-ready private/support method; score and owner/emitter unchanged.
- Summary/evidence: accepted B005 current MCP session `b010_00032w_20260703` proved UID000204 has an exact source-shaped raw body, no IDA function object, no ordinary xrefs, no pointer-pattern hits, unique body bytes, parser item-vector writes, paint inline traversal, and exact padding/constructor boundaries. No-function/no-xref evidence caps public API confidence, while the method body preserves the original lack of an `index < 0` guard.

### 2026-07-03 - B004 UID000202 constructor declaration callback

- Before: formal support declarations had `RankingRewardEntry` fields but no default-constructor declaration, leaving [UID:000202][0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit](by-memory/0x0045d790-0x0045d7c2.RankingRewardEntryVectorInit.md) easy to misread as still blocked by missing declarations.
- Changed to: added `RankingRewardEntry();` to the emitted support struct and placed `[[CHILDREN]]` after the support declarations so the constructor body emits at file scope; score and owner/emitter unchanged.
- Summary/evidence: accepted B004 current MCP session `b010_00032w_20260703` proved UID000202 is a source-ready `RankingRewardEntry::RankingRewardEntry()` out-of-line constructor with no IDA function object, failed raw-start decompile, exact writes to `itemsBegin/itemsEnd/itemsCapacity` and `symbolFrameIndex`, no ordinary xrefs, no pointer-pattern hits, adjacent [UID:000203][0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk](by-memory/0x0045d7d0-0x0045d7db.RankingRewardEntryItemVectorUnwindThunk.md) cleanup thunk/parser boundary, and no initialization of text buffers, `symbolAttribute`, or reserved bytes.

### 2026-06-30 - B006 narrowed empty-emitter callback

- Before: `87/91`, owner/emitter through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), with all formal C++ blank because the full dialog class and packet/listener interface were not source-ready.
- Changed to: score and owner/emitter unchanged; formal C++ now emits only the support declarations `RankingRewardItem` and `RankingRewardEntry`.
- Summary/evidence: B006 current MCP request id `2016` reconfirmed the reward-entry and reward-item declaration shapes at report-level detail: `RankingRewardEntry` is `0x230` bytes with rank-start text, rank-end text, symbol text, `symbolFrameIndex`, packet-backed `symbolAttribute`, alignment, and a nested item-vector triplet; `RankingRewardItem` is `0x208` bytes with name, quantity, icon id, palette index, and one reserved byte. No full `RankingRewardInfoDialog` class or method bodies were emitted because packet/listener and dialog-member APIs remain accepted blockers.

### 2026-06-23 - B001 accepted reward-dialog source-quality sync

- Before: `86/90`, with reward parser/vector ownership resolved but no current-session packet-handler refresh from the accepted report.
- Changed to: `87/91`, owner/emitter unchanged through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), final C++ blank.
- Summary/evidence: current MCP session `80de0a67` reconfirmed `0x0045ddd0` opcode `0x7d` subcommand `5` handling, selected-category validation through `g_pRankingDialog + 0x26c`, reward-entry parsing/deep-copy/cleanup, request-helper sender normalization, and UID0003X8 exclusion from the class. Later dedicated review resolves its destination as non-emitting compiler/UCRT support rather than `StringUtil`.

### 2026-06-16 - B001 ranking reward/vector source-quality execution

- Before: `84/88`.
- Changed to: `86/90`, owner/emitter unchanged through [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), final C++ blank.
- Summary/evidence: accepted B001's heuristic/source-quality reanalysis for `RankingRewardEntry`, `RankingRewardItem`, reward vector helper ownership, and the [UID:0001ZI][0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers](by-memory/0x0045eae0-0x0045efd0.RankingRewardVectorStorageHelpers.md) split. Reward helper children [UID:0003X6][0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth](by-memory/0x0045eae0-0x0045ec43.RankingRewardItemVectorInsertWithGrowth.md), [UID:0003X7][0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth](by-memory/0x0045ec50-0x0045ef1f.RankingRewardEntryVectorInsertWithGrowth.md), and [UID:0003X9][0x0045ef50-0x0045efd0.RankingRewardItemVectorClone](by-memory/0x0045ef50-0x0045efd0.RankingRewardItemVectorClone.md) route here; later UID0003X8 review supersedes its old `StringUtil` route with non-emitting compiler/UCRT support.

### 2026-06-04 - Parent assignment and stale source cleanup

- Before: class score was already `84/88`, but reconstructable/autogen metadata was blank and the page still referenced stale recovered-source artifacts.
- Changed to: marked reconstructable, attached to [UID:0000MZ][RankingDialog](by-file/RankingDialog.md), and removed stale recovered-source wording without changing the score.
- Summary/evidence: live IDA reconfirmed [UID:0001ZF][0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors](by-memory/0x0045d7e0-0x0045db54.RankingRewardEntryParseAndAccessors.md) as ranking reward-info behavior called from the opcode `0x7d` subcommand `5` packet handler.

### 2026-05-30 - Grading update

- Before: this class had exact packet/parser/storage memory coverage and data layout notes but remained unevaluated by the completion/confidence header.
- Changed to: score is now `84/88`, reflecting documented dialog construction/close/paint/destructor, opcode `0x7d` subcommand `5` handler, reward-entry/item layout, vtables, globals, and nested vector storage helpers.
- Summary/evidence: linked memory pages record the core dialog range, reward-entry parser/accessors, packet handler, vector storage, vector destroy, range allocation helpers, 560-byte reward records, and 520-byte item rows.

### 2026-05-27 - Added exact packet/parser/storage memory coverage

- Before: the class listed `HandleRewardInfoPacket` and reward containers by address only, and did not identify that active generated source omits the packet-handler and helper bodies.
- Changed to: linked exact memory pages for the core class range, reward-entry parser/accessors, packet handler, vector storage helpers, reward-entry vector destroy helper, and range allocation helpers.
- Summary/evidence: IDA confirms the `0x0045ddd0` opcode `0x7d` subcommand `5` handler, parser call to `0x0045d7e0`, 560-byte reward-entry records, 520-byte item rows, and nested-vector deep-copy/destruction helpers through `0x0045f33a`.
